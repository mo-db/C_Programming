#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-15_temp_with_function"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"