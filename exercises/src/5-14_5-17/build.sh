#!/bin/bash

set -xe

CFLAGS="-g"
LIBS=""

#FILE="2-2_ok_loop"
FILE="5-14_qsort_test"
#LIB="io"

clang $CFLAGS -o ./out/$FILE ./src/$FILE.c

"./out/$FILE"