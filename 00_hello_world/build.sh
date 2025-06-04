#!/bin/sh

mkdir -p build
emcc -o build/index.html hello.c
