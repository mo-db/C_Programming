@echo off

SET "CFLAGS="
SET "LIBS="
SET "FILE=4-13_reverse_recursive"

gcc %CFLAGS% -o output\%FILE% src\%FILE%.c

output\%FILE%.exe