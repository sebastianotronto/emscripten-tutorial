#!/bin/sh

mkdir -p build
emcc -sEXPORTED_FUNCTIONS=_multiply -sMODULARIZE -sEXPORT_NAME=MyLibrary \
	-o build/library.mjs library.c
