#!/bin/sh

mkdir -p build
emcc -sEXPORTED_FUNCTIONS=_primes_in_range -sMODULARIZE -sEXPORT_NAME=Primes \
	-sEXPORTED_RUNTIME_METHODS=addFunction,UTF8ToString \
	-sALLOW_TABLE_GROWTH \
	-pthread -sPTHREAD_POOL_SIZE=16 \
	-o build/primes.mjs primes.c
