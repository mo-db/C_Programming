@echo off

SET "CFLAGS=-g"
SET "LIBS="
SET "FILE=my_sort"

clang %CFLAGS% src\%FILE%.c -o out\%FILE%.exe

out\%FILE%