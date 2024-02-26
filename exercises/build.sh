#!/bin/bash

set -xe

CFLAGS="-g"
LIBS=""

#FILE="2-2_ok_loop"
FILE="5-13_mytail"
#LIB="io"

clang $CFLAGS -o ./output/$FILE ./src/$FILE.c

#"./output/$FILE"