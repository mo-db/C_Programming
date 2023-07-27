#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-11-1_countOccur"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"