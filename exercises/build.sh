#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-8_countStuff"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c