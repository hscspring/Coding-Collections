use hello_macro::HelloMacro;
use hello_macro_derive::HelloMacro;

#[derive(HelloMacro)]
struct Pancakes2;

struct Pancakes1;

impl HelloMacro for Pancakes1 {
    fn hello_macro() {
        println!("Hello, Macro! My name is Pancakes1!");
    }
}

fn main() {
    Pancakes1::hello_macro();
    Pancakes2::hello_macro();
}
