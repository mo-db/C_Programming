#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-11_printInputWord"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"