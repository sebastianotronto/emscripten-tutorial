#include <stdio.h>

int primes_in_range(int, int);

int main() {
	int low = 1;
	int high = 10000000;
	int result = primes_in_range(low, high);
	printf("There are %d primes between %d and %d\n", result, low, high);
}
