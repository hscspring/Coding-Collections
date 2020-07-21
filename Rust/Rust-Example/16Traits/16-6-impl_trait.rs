use std::iter;
use std::vec::IntoIter;

// This function combines two `Vec<i32>` and returns an iterator over it.
// Look how complicated its return type is!
fn _combine_vecs_explicit_return_type<'a>(
    v: Vec<i32>, u: Vec<i32>,
) -> iter::Cycle<iter::Chain<IntoIter<i32>, IntoIter<i32>>> {
    v.into_iter().chain(u.into_iter()).cycle()
}

// This is the exact same function, but its return type uses `impl Trait`.
// Look how much simpler it is!

fn _combine_vecs<'a>(
    v: Vec<i32>,
    u: Vec<i32>,
) -> impl Iterator<Item=i32> {
    v.into_iter().chain(u.into_iter()).cycle()
}


// Returns a function that adds `y` to its input
fn make_adder_function(y: i32) -> impl Fn(i32) -> i32 {
    let closure = move |x: i32| { x + y };
    closure
}

fn double_positives<'a>(numbers: &'a Vec<i32>) -> impl Iterator<Item = i32> + 'a {
    numbers
        .iter()
        .filter(|x| x > &&0)
        .map(|x| x * 2)
}

fn main() {
    let plus_one = make_adder_function(1);
    assert_eq!(plus_one(2), 3);

    let vec = vec![1, 2, 3, 4, 5, 6];
    let mut dp_vec = double_positives(&vec);
    println!("Four consecutive `next` calls on vec");
    println!("> {:?}", dp_vec.next());
    println!("> {:?}", dp_vec.next());
    println!("> {:?}", dp_vec.next());
    println!("> {:?}", dp_vec.next());
}