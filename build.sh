#! /bin/bash

rm  ./build/TRustC

cd ./src
    bison -d parser.y
    if [[ $? -ne 0 ]]; then
    echo -e "Parsing error \n";
    fi
    flex lexer.l
    gcc -o ./TRustC parser.tab.c lex.yy.c
    rm lex.yy.c
    rm parser.tab.c
    rm parser.tab.h
    mv ./TRustC ../build/TRustC
cd ..