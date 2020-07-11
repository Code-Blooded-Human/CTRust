# TRust
This document outlines features of rust programming lanuage.


## Table of Contents (Optional)


- [Variables and Consts](#Variables\ Consts) 
- [Functions](#Functions)
- [Conditionals](#Conditionals)
- [Team](#team)
- [FAQ](#faq)
- [Support](#support)
- [License](#license)

# Variables Consts
[Reference from official documentation](https://doc.rust-lang.org/beta/book/ch03-01-variables-and-mutability.html)
## Variables
### General syntax for declaration, assigning.

let ``identifier`` = ``expression`` ; <br>
let mut ``identifier`` = ``expression`` ; <br>
let ``identifier`` : ``type`` = ``expression`` ; <br>
let mut ``identifier`` : ``type`` = ``expression`` ; <br>
let mut ``identifier`` ; <br>
let mut ``identifier`` : ``type`` ; <br>
``identifier`` = ``expression``;
```rust
let ILP = "Introduction to lanuage processing";
let mut grade = "A";
let marks : i32 = 100;
let mut sq2 = square(2)*2;
let mut notAssigned;
let mut vartype:i32;

//Some other valid examples
let d = true;
let e = !d;
e = !!e;
let f = (true || d) && (a && b) || false && true;
let c = 5 * a;
c = c++;
c += d;
c = this.something;
let mut k = 10;
a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
a = area(a*3,b*7);
a = area(10,b%5)%10;
```

## Constants
### General syntax for declaration, assigning.
const ``identifier`` = ``expression``; <br>
const ``identifier`` : ``type`` = ``expression``; <br>
```rust
const con = "test";
const cont : i32 = 5;
```
# Structs
## syntax

# Vectors
## syntax


# Functions
main is the entry point function, all valid rust programs should have main function. The syntax analyser checks for valid defination of main. The main function cannot be called by user.
## Syntax for declaration of functions.
fn ``indentifier``(){``code``} <br>
fn ``indentifier``(``indetifer``:``type``,``indetifer``:``type``){``code``} <br>
fn ``indentifier``()->`returnType`{``code``} <br>
fn ``indentifier``(``indetifer``:``type``,``indetifer``:``type``)->``returnType``{``code``} <br>
```rust
fn another_function(x: i32)->i:32 {
    println!("The value of x is: {}", x);
    return x;
}
```

## Syntax for calling of functions.
``indentifier``(``params``);<br>
``indetifier`` = ``indentifier``(); <br>
let ``indetifier`` = ``indentifier``(); <br>
``indentifier``();<br>
``indetifier`` = ``indentifier``(``params``); <br>
let ``indetifier`` = ``indentifier``(``params``); <br>
```rust
let area_sqaure10x20 = area(10,20);
a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
sqaure();
```

# Conditionals
## syntax
``if`` ``expression`` { ``code`` } <br>
``if`` ``expression`` { ``code`` } else {``code``}<br>
``if`` ``expression`` { ``code`` } else if ``expression`` {``code``}<br>
``if`` ``expression`` { ``code`` } else if ``expression`` {``code``} else {``code``}<br>
```rust
if number < 5 {
    println!("condition was true");
}

if number < 5 {
    println!("condition was true");
} else {
    println!("condition was false");
}

if number < 5 {
    println!("condition was true");
} else if number > 10 {
    println!("else if condition true");
} else {
    println!("condition was false");
}
```

# Loops
## for syntax
## while loop


