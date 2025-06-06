#include <stdio.h>
#include <stdbool.h>

#include "primes.h"

#define FILENAME "/assets/primes_table"

bool read_table(unsigned char *table) {
	FILE *f = fopen(FILENAME, "rb");
	if (f == NULL)
		return false;

	int b = fread(table, TABLESIZE, 1, f);
	fclose(f);

	return b == 1;
}

bool store_table(const unsigned char *table) {
	FILE *f = fopen(FILENAME, "wb");
	if (f == NULL)
		return false;

	int b = fwrite(table, TABLESIZE, 1, f);
	fclose(f);

	return b == 1;
}
