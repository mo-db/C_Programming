#!/bin/bash

set -xe

CFLAGS=""
LIBS=""

#FILE="2-2_ok_loop"
FILE=testing

gcc $CFLAGS -o ./output/$FILE ./src/$FILE.c

"./output/$FILE"