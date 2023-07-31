#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-16-1_print_longest_line"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"