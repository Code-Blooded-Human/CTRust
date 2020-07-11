# TRustC
Transpile Rust to C.


## Note from developers
We have only completed upto syntax analysis part of transpiler, The checkSyntax.sh only checks for syntatically errors/

## Goal of project
This project intends to transpile a code written in Rust to C. For phase 1 we consider only selected aspects of Rust. We may later improve the transpiler to transpile standard Rust. We hereby define TRust as subset of Rust which may not contain all features. 

## TRust
Please refer [TRust Doc](docs\TRust.md "Syntax Documentation of Rust that we have implemented") to know the syntax of Rust and which feature subsets we have implemented.


## Installation

### Clone

- Clone this repo to your local machine.

### Setup

- change directory to CTRust folder.

> Install Bison and Flex 

```shell
CTRust$ sudo apt-get install bison flex
```

> Make ./build.sh executable

```shell
CTRust$ sudo chmod +x ./build.sh
```

> Make ./build/checkSyntax.sh executable

```shell
CTRust$ sudo chmod +x ./build/buildSyntax.sh
```
> Run ./build.sh, this generates a executable in build folder.

```shell
CTRust$ ./build.sh
```
> change directory to build and execute checkSyntax.sh on appropriate rust script.

```shell
CTRust$ cd build
CTRust/build$ ./checkSyntax.sh test.sh
```
