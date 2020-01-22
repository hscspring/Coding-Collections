// option1.rs
// This example panics because the second time it calls `pop`, the `vec`
// is empty, so `pop` returns `None`, and `unwrap` panics if it's called
// on `None`. Handle this in a more graceful way than calling `unwrap`!
// Execute `rustlings hint option1` for hints :)

// Solotion 1

// pub fn pop_too_much() -> bool {
//     let mut list = vec![3];

//     let last = list.pop().unwrap();
//     println!("The last item in the list is {:?}", last);

//     let second_to_last = list.pop();
//     match second_to_last {
//         Some(second_to_last) => {
//             println!("The second-to-last item in the list is {:?}", second_to_last);
//         },
//         None => {
//             println!("vector is empty.");
//         }
//     }
//     true
// }


// Solotion 2

// pub fn pop_too_much() -> bool {
//     let mut list = vec![3];

//     let last = list.pop().unwrap();
//     println!("The last item in the list is {:?}", last);

//     let second_to_last = list.pop().unwrap_or(0);
//     println!("The second-to-last item in the list is {:?}", second_to_last);
//     true
// }


// Solotion 3

pub fn pop_too_much() -> bool {
    let mut list = vec![3];

    let last = list.pop().unwrap();
    println!("The last item in the list is {:?}", last);

    if let Some(second_to_last) = list.pop() {
        println!("The second-to-last item in the list is {:?}", second_to_last);
    }
    
    true
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn should_not_panic() {
        assert!(pop_too_much());
    }
}
