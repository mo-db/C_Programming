#!/bin/bash

set -xe

CFLAGS="-g"
LIBS="/usr/local/lib/raylib-5.0_macos"

#FILE="2-2_ok_loop"
FILE="main"
#LIB="io"

clang $CFLAGS -I$LIBS/include -L$LIBS/lib -o ./out/$FILE ./src/$FILE.c

"./out/$FILE"