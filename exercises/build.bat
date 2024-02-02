@echo off

SET "CFLAGS="
SET "LIBS="
SET "FILE=4-3_calculator"

gcc %CFLAGS% -o output\%FILE% src\%FILE%.c

output\%FILE%.exe