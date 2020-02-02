struct Owner(i32);

impl Owner {
    // Annotate lifetimes as in a stadalone function
    fn add_one<'a>(&'a mut self) { self.0 += 1; }
    fn print<'a>(&'a self) {
        println!("`print`: {}", self.0);
    }
}

impl Owner {
    fn add_one(&mut self) { self.0 += 1; }
    fn print(&self) {
        println!("`print`: {}", self.0);
    }
}


fn main() {
    let mut owner = Owner(18);
    owner.add_one();
    owner.print();
}