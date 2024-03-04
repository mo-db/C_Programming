#!/bin/bash

set -xe

CFLAGS="-g"
LIBS=""

#FILE="2-2_ok_loop"
FILE="operation_exercise"
#LIB="io"

clang $CFLAGS -o ./out/$FILE ./src/$FILE.c

"./out/$FILE"