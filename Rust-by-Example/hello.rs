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
    #[allow(dead_code)]
    struct Structure(i32);
}
