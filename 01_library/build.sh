#!/bin/sh

mkdir -p build
emcc -sEXPORTED_FUNCTIONS=_multiply -o build/library.js library.c
