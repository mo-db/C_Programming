#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

FILE="1-21_entab"
gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"