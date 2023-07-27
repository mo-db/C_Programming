#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-9_replaceBlanks"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"