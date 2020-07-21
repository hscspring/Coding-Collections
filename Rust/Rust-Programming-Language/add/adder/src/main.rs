use rand;
use add_one;

fn main() {
    let num = 10;
    println!("hello, world! {} plus one is {}!", num, add_one::add_one(num));
    println!("Hello, world!");
}
