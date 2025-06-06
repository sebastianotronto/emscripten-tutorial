#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#include "primes.h"
#include "storage.h"

#define NTHREADS 16
#define INDEX(i) ((i) >> 3)
#define MASK(i) (unsigned char)(1 << ((i) % 8))

unsigned char primes_table[TABLESIZE];
struct interval { int low; int high; int count; };

void *pthread_routine(void *);
int primes_in_range(int, int, void (*)(const char *));
void set_nonprime(unsigned char *, int);
bool isprime(const unsigned char *, int);

int primes_in_range(int low, int high, void (*log)(const char *)) {
	static bool table_is_loaded = false;

	pthread_t threads[NTHREADS];
	struct interval args[NTHREADS];

	if (low < 0 || high < low)
		return 0;

	if (!table_is_loaded) {
		if (!read_table(primes_table)) {
			generate_primes(primes_table, log);
			if (!store_table(primes_table))
				log("Error storing table to indexed DB");
		}
		
		table_is_loaded = true;
	}

	int interval_size = (high-low)/NTHREADS + 1;
	for (int i = 0; i < NTHREADS; i++) {
		args[i].low = low + i*interval_size;
		args[i].high = args[i].low + interval_size;
		pthread_create(&threads[i], NULL, pthread_routine, &args[i]);
	}

	log("All threads have started, computing..."); 

	int result = 0;
	for (int i = 0; i < NTHREADS; i++) {
		pthread_join(threads[i], NULL);
		result += args[i].count;
	}

	return result;
}

void set_nonprime(unsigned char *table, int n) {
	table[INDEX(n)] &= ~MASK(n);
}

bool isprime(const unsigned char *table, int n) {
	return table[INDEX(n)] & MASK(n);
}

void generate_primes(unsigned char *table, void (*log)(const char *)) {
	memset(table, 0xFF, TABLESIZE);
	set_nonprime(table, 0);
	set_nonprime(table, 1);
	for (long long i = 0; i < MAX_PRIME; i++) {
		if (i % 100000000 == 0 && log != NULL) {
			char msg[200];
			sprintf(msg, 
			    "Could not read table of primes, generating it\n"
			    "Done %llu / %d", i, MAX_PRIME);
			log(msg);
		}
		if (!isprime(table, i))
			continue;
		for (long long int j = 2*i; j < MAX_PRIME; j += i)
			set_nonprime(table, j);
	}
}

void *pthread_routine(void *arg) {
	struct interval *interval = arg;

	interval->count = 0;
	for (int i = interval->low; i < interval->high; i++)
		if (isprime(primes_table, i))
			interval->count++;

	return NULL;
}
