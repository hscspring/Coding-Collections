use std::ops::Deref;

struct MyBox<T>(T);

impl<T> MyBox<T> {
	fn new(x: T) -> MyBox<T> {
    	MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    // defines an associated type for the Deref trait to use
	type Target = T;

    // &self.0, returns a reference to the value we want to access with the * operator
    fn deref(&self) -> &T {
    	&self.0
    }
}

fn hello(name: &str) {
    println!("Hello, {}!", name);
}

fn main() {
    let m = MyBox::new(String::from("Rust"));
    hello(&m);
    hello(&(*m)[..]);
    let n = String::from("RUST");
    hello(&n[..]);
}

