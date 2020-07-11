
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

fn noReturn()
{
    if((true || d) && (a && b) || false && true)
    {
        if 5 != 3 || a >= b || 2 >1
        {
        }
        a = 5;
        // else if (a == b)
        // {
        //     //NOT VALID
        // }

    }else if ( a == b)
    {
        let f = (true || d) && (a && b) || false && true;
        let c = 5 * a;
        c = c++;
        c += d;
    } else
    {
        a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
        a = area(a*3,b*7);
    }

    // fn cannot_define()
    // {
    //     printf("You cannot define function here!!");
    // }
 
}
let area_sqaure10x20 = area(10,20);
a = area(area(area(a,area(area(a,b)*area(a,b),b)),b),a);
a = area(a*3,b*7);
a = area(10,b%5)%10;

fn main() // COMMENT MAIN TO GET AN ERROR
{
    area(10,30,"Extra param will give error");
}


// fn test()
// {
//     undeclaredFunction();
// }
fn neverUsed()
{
    main();
}