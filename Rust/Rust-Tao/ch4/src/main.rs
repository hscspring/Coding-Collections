struct A {
    a: u32,
    b: Box<u64>,
}

struct B(i32, f64, char);

struct N;

enum E {
    H(u64),
    M(Box<u32>)
}

union U {
    u: u32,
    v: u64
}

fn main() {
    println!("Hello, world!");
    println!("Box<u32>: {:?}", std::mem::size_of::<Box<u32>>());
    println!("A: {:?}", std::mem::size_of::<A>());
    println!("B: {:?}", std::mem::size_of::<B>());
    println!("N: {:?}", std::mem::size_of::<N>());
    println!("E: {:?}", std::mem::size_of::<E>());
    println!("U: {:?}", std::mem::size_of::<U>());
}
