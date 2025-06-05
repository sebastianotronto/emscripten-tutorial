#!/bin/sh

mkdir -p build
emcc -sEXPORTED_FUNCTIONS=_primes_in_range -sMODULARIZE -sEXPORT_NAME=Primes \
	-pthread -sPTHREAD_POOL_SIZE=16 \
	-o build/primes.mjs primes.c
