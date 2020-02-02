// Comment //
// this is comment
/* hello
 *
*/
//! Generate library docs for the enclosing item.
/// some



fn main() {
    // Print //
    println!("Hello world!");
    let x = 5 + /* 90 + */ 5;
    println!("Is `x` 10 or 100? x = {}", x);


    /*    1-2 Print    */

    println!("{0}, this is {1}. {1}, this {0}", "Alice", "Bob");
    println!("{} days", 31);
    println!("{subject} {verb} {object}",
             object="tha lazy dog",
             subject="the quick brown fox",
             verb="jumps over");
    println!("{} of {:b} people know binary, the other half doesn't", 1, 2);
    println!("{number:>width$}", number=1, width=6);
    println!("{number:>0width$}", number=1, width=6);
    println!("My name is {0}, {1} {0}", "Bond", "James");

    // #[allow(dead_code)]
    #[derive(Debug)]
    struct Structure(i32);
    let st = Structure(3);
    println!("This struct `{:?}` won't print...", st);

    let pi = 3.141592;
    println!("Pi is roughly {0:.3}", pi);

    println!("Hello is {:.*}",    5, 0.01);


    /*    1-2-1 Debug    */
    
    // Put a `Structure` inside of the structure `Deep`. Make it printable
    // also.
    #[derive(Debug)]
    struct Deep(Structure);

    // Printing with `{:?}` is similar to with `{}`.
    println!("{:?} months in a year.", 12);
    println!("{1:?} {0:?} is the {actor:?} name.",
             "Slater",
             "Christian",
             actor="actor's");

    // `Structure` is printable!
    println!("Now {:?} will print!", Structure(3));
    
    // The problem with `derive` is there is no control over how
    // the results look. What if I want this to just show a `7`?
    println!("Now {:?} will print!", Deep(Structure(7)));

    #[derive(Debug)]
    struct Person<'a> {
        name: &'a str,
        age: u8
    }

    let name = "Peter";
    let age = 27;
    let peter = Person { name, age };

    // Pretty print
    println!("{:#?}", peter);
    println!("{:?}", peter);
}
