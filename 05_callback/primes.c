#include <stdbool.h>
#include <pthread.h>

#define NTHREADS 16

bool isprime(int);
void *pthread_routine(void *);

struct interval { int low; int high; int count; };

int primes_in_range(int low, int high, void (*log)(const char *)) {
	pthread_t threads[NTHREADS];
	struct interval args[NTHREADS];

	if (low < 0 || high < low)
		return 0;

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

bool isprime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void *pthread_routine(void *arg) {
	struct interval *interval = arg;

	interval->count = 0;
	for (int i = interval->low; i < interval->high; i++)
		if (isprime(i))
			interval->count++;

	return NULL;
}
