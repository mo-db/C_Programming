#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

#FILE="2-2_ok_loop"
FILE="4-3_polish_calculator"
#LIB="io"

gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c #./src/$LIB.c

"./output/$FILE"