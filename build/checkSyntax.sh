#! /bin/bash

EXEC=./TRustC



if [ -f "$EXEC" ]; then
    if [[ $# -eq 0 ]]; then
        echo -e "\e[31m[USAGE] checkSynatax.sh filename.rs \e[0m"
        exit;
    fi
    if [ ! -f $1 ];then
        echo -e "\e[31m[ERROR] File not found \e[0m";
    fi
else
    echo "Please run build.sh to generate an exec \n"
    exit;
fi

cat $1 | ./TRustC
