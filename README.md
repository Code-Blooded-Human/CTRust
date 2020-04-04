# TRustC
Transpile Rust to C.
## Goal of project
This project intends to transpile a code written in Rust to C. For phase 1 we consider only selected aspects of Rust. We may later improve the transpiler to transpile standard Rust. We hereby define TRust as subset of Rust which may not contain all features. 

## TRust
Please refer [TRust Doc](docs\TRust.md "Syntax Documentation of Rust that we have implemented") to know the syntax of Rust and which feature subsets we have implemented.

## GOAL 1
### Lexical analyser.
We implement following features in lexical analyser.
* variables
* expressions
* for loops
* while loops
* functions
