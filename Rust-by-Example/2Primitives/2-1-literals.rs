fn main() {

    /*    Primitives    */

    // type annotated
    let logical: bool = true;

    // Regular annoatation
    let a_float: f64 = 1.0;
    // Suffix annotation
    let an_integer = 5i32;

    // Or a default
    let default_float = 3.0; // f64
    let default_integer = 7; // i32

    // A mutable vairable's value can be changed
    let mut mutable = 12;
    mutable = 21;

    // Error, the type of a variable cannot be changed
    // mutable = true;

    // overwritten with shadowing
    let mutable = true;


    /*    2-1 Literals and operators    */

    // Integer addition
    println!("1 + 2 = {}", 1u32 + 2);

    // Integer subtraction
    println!("1 - 2 = {}", 1i32 - 2);
    // TODO ^ Try changing `1i32` to `1u32` to see why the type is important
    // Error, 1-2=-1, is not u32
    // println!("1 - 2 = {}", 1u32 - 2);

    // Short-circuiting boolean logic
    println!("true AND false is {}", true && false);
    println!("true OR false is {}", true || false);
    println!("NOT true is {}", !true);

    // Bitwise operations
    println!("0011 AND 0101 is {:04b}", 0b0011u32 & 0b0101);
    println!("0011 OR 0101 is {:04b}", 0b0011u32 | 0b0101);
    println!("0011 XOR 0101 is {:04b}", 0b0011u32 ^ 0b0101);
    println!("1 << 5 is {}", 1u32 << 5);
    println!("0x80 >> 2 is 0x{:x}", 0x80u32 >> 2);

    // Use underscores to improve readability!
    println!("One million is written as {}", 1_000_000u32);
}


