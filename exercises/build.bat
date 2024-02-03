@echo off

SET "CFLAGS="
SET "LIBS="
SET "FILE=4-2_atof-extended"

gcc %CFLAGS% -o output\%FILE% src\%FILE%.c

output\%FILE%.exe