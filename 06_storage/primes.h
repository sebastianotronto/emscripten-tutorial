#ifndef PRIMES_H
#define PRIMES_H

#include <limits.h>

#define MAX_PRIME INT_MAX
#define TABLESIZE (1 << 28)

int primes_in_range(int, int, void (*)(const char *));
void generate_primes(unsigned char *, void (*)(const char *));

#endif
