# TRust
This document outlines features of rust programming lanuage.


## Table of Contents (Optional)


- [Variables and Consts](#Variables\ Consts) 
- [Structures](#Structs)
- [Vectors](#vectors)
- [Functions](#Functions)
- [Conditionals](#Conditionals)
- [Loops](#Loops)


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
[Reference from official documentation](https://doc.rust-lang.org/book/ch05-01-defining-structs.html)
## syntax for declaration
struct ``identifier`` { ``identifier``:``type``,``identifier``:``type``,..}<br>
```rust
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}
```
## syntax for using
```rust
let mut user1 = User {
    email: String::from("someone@example.com"),
    username: String::from("someusername123"),
    active: true,
    sign_in_count: 1,
};

user1.email = String::from("anotheremail@example.com");
```

# Vectors
## syntax


# Functions
[Reference from official documentation](https://doc.rust-lang.org/book/ch03-03-how-functions-work.html)<br>
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
[Reference from offical documentation](https://doc.rust-lang.org/book/ch03-05-control-flow.html) <br>
## syntax
``if`` ``expression`` { ``code`` } <br>
``if`` ``expression`` { ``code`` } else {``code``}<br>
``if`` ``expression`` { ``code`` } else if ``expression`` {``code``}<br>
``if`` ``expression`` { ``code`` } else if ``expression`` {``code``} else {``code``}<br>
```rust
if number < 5 {
    println!("condition was true");
}

if number < (true || d) && (a && b) || false && true {
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
[Reference from offical documentation](https://doc.rust-lang.org/1.2.0/book/for-loops.html) <br>
## for loop syntax
for ``variable`` ``start_int``..``stop_int``{``code``}
```rust
for x in 0..10 {
    if x % 2 == 0 { continue; }
    if x == 8 {break;}
    println!("{}", x);
}
```
## while loop syntax
while ``boolean_conditon`` {``code``}
```rust
let mut x = 5; // mut x: i32
let mut done = false; // mut done: bool

while !done {
    x += x - 3;

    println!("{}", x);

    if x % 5 == 0 {
        done = true;
    }
}
```

