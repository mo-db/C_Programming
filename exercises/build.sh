#!/bin/bash

set -xe

CFLAGS="-g"
LIBS=""

#FILE="2-2_ok_loop"
FILE="6-2_wtf"
#LIB="io"

clang $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"
