#!/bin/sh

mkdir -p build
cc -o build/native primes.c native.c
