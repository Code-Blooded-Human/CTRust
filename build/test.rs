
// Global variables
let a = 5;
let b = "Hi hello how are you!!";
let d = true;
let e = !d;
e = !!e;
let f = (true || d) && (a && b) || false && true;
let c = 5 * a;
c = c++;
c += d;
c = this.something;
let mut k = 10;
const k = 5;


// lt wrong = right;
// let text = " ILP "";
// let a = 5
// let c += d; //WRONG 
// let f = (true || ) && a || b;



fn area(l:i32,b:i32)->i32
{
    return l*b;
}

// fn noReturn()
// {
//     if((true || d) && (a && b) || false && true)
//     {
//         if 5 != 3 || a >= b || 2 >1
//         {
//         }
//         a = 5;
//         // else if (a == b)
//         // {
//         //     //NOT VALID
//         // }

//     }else if ( a == b)
//     {
//         let f = (true || d) && (a && b) || false && true;
//         let c = 5 * a;
//         c = c++;
//         c += d;
//     } else
//     {
//         a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
//         a = area(a*3,b*7);
//     }

//     // fn cannot_define()
//     // {
//     //     printf("You cannot define function here!!");
//     // }
 
// }
let area_sqaure10x20 = area(10,20);
a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
a = area(a*3,b*7);
a = area(10,b%5)%10;



//Struct Declaration

struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}


// Using Tuple Structs without Named Fields to Create Different Types

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);


fn main() // COMMENT MAIN TO GET AN ERROR
{
    // area(10,30,"Extra param will give error");

    // If these loops and if else block is used outside a function then parser will give error

    //If else block

    if n < -10 {
        let mut a = b;
    } else if n > 0 {
        let mut a = c;
    } else {
        let mut a = d;
    }

    if (5-2) && (n+3) {
        let mut a = b;
    }

    if !true {
        let mut a = b;
    }


    //while loop

    let mut x = 5; // mut x: i32
    let mut done = false; // mut done: bool

    while !done {
        x += x - 3;

        area(a*3,b*7);

        if x % 5 == 0 {
            done = true;
        }
    }

    //infinite loop in rust using loop and use break to break out early.

    loop {
        x += x - 3;
        if x % 5 == 0 { break; }
    }


    //For Loop

    for x in 0..10 {
        area(a*3,b*7);
    }

    // For loop with continue statement 

    for x in 0..10 {
        if x % 2 == 0 { continue; }
        area(a*3,b*7);
    }
    


}


// fn test()
// {
//     undeclaredFunction();
// }
// fn neverUsed()
// {
//     main();
// }