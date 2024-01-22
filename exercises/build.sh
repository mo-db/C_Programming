#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

#FILE="2-2_ok_loop"
FILE="3-3_expand"
#LIB="io"

gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c #./src/$LIB.c

"./output/$FILE"