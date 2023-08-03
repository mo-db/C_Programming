#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="2-1_count_ranges"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"