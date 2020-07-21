struct Duck;
struct Pig;

trait Fly {
    fn fly(&self) -> bool;
}

impl Fly for Duck {
    fn fly(&self) -> bool {
        true
    }
}

impl Fly for Pig {
    fn fly(&self) -> bool {
        false
    }
}

fn fly_static<T: Fly>(s: T) -> bool {
    s.fly()
}

fn fly_dyn(s: &Fly) -> bool {
    s.fly()
}

fn main() {
    println!("Hello, world!");
    let pig = Pig;
    assert_eq!(fly_static::<Pig>(pig), false);
    let duck = Duck;
    assert_eq!(fly_static::<Duck>(duck), true);
    assert_eq!(fly_dyn(&Pig), false);
    assert_eq!(fly_dyn(&Duck), true);
}
