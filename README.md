# How to port a complex C codebase to the web

This repository contains the source code for the examples discussed in
[this blog post / tutorial](https://sebastiano.tronto.net/blog/2025-06-06-webdev).

Each sub-folder is a self-contained example of a C or C++ program (or
library) that can be compiled to [WebAssembly](https://webassembly.org/)
using [Emscripten](https://emscripten.org), and some JavaScript and HTML
code that can be used to run this program in a web page or in a JavaScript
runtime such as [Node.js](https://nodejs.org).  Following these steps in
order will walk you through the process of deploying a complex application
(including multithreading, persistent storage and callback functions)
as a web app.

Besides the source files, each folder contains a few one-line shell
scripts, for convenience. Usually, the following are present:

* `build.sh`: to compile the C code with Emscripten.
* `run-node.sh`: to run an example program in Node.js.
* `run-server.sh`: to start a web server on
  [localhost:8080](http://localhost:8080) running an example web page
  (require darkhttpd, see below).

If one of the `run-*` scripts is missing, it means that that example
is only meant to run in Node.js, or only as a script in a web page.

The examples have been tested only on Linux, but should work on any
UNIX system, and should be easy to adapt to Windows or other OSes.
Pull requests are welcome.

## Prerequisites

In order to follow this tutorial, you are going to need the following:

1. [Emscripten](https://emscripten.org)
2. A web server to run locally, such as
   [darkhttpd](https://github.com/emikulic/darkhttpd)
3. [Node.js](https://nodejs.org) (this is optional, since a version
   of Node.js is distributed together with emscripten).

## 0. Hello world

The folder `00_hello_world` contains the simplest possible example:
a C program that prints "Hello world" to standard output. The default
Emscripten HTML template is used to run this code in a web page.

## 1. Building a library

A common use case for building C or C++ code to WebAssembly is using some
high-performance library in a web app. In this situation, the code you
want to build does not have a `main()` entry point, but instead its public
functions are called from JavaScript. Motivated by this, in the folder
`01_library` you'll find an extremely simple C library (with only one
one-line function), and some JavaScript code to run it from a web page.

## 2. Making it a module

In `02_library_modularized` we review
the previous example and we build it into a
[module](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules).
The result is the same, but it is more convenient to use.

## 3. Multi-threading

In `03_threads` we build a more complicated example based on
[pthreads](https://en.wikipedia.org/wiki/Pthreads). To run this
example, the web server has to be configured to provide the correct
`Cross-Origin-*` headers, see `03_threads/run-server.sh` for details.

## 4. Don't block the main thread

In `04_no_block` we avoid our calculations blocking the main browser
thread by using a web worker.

## 5. Callback functions

In `05_callback` the example is extended to include a callback function.
The C program uses this function to log its progress back to the
JavaScript side.

## 6. Storage

In `06_storage` we show how to use Emscripten's
[file system API](https://emscripten.org/docs/api_reference/Filesystem-API.html)
using as backend the
[indexed DB](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API).
This example only works in the browser, as other runtimes (such as
Node.js) require different backends.

In this example we make use time of the `--pre-js` option of the
compiler to include custom JavaScript code that is run when our module
loads. Moreover, the C code is split into multiple files for convenience.
