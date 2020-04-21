#! /bin/bash

rm  ./build/TRustC

flex -o ./src/lex.yy.c ./src/lexer.l
gcc -o ./build/TRustC ./src/main.c ./src/lex.yy.c
rm ./src/lex.yy.c
