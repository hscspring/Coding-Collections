fn main() {
    let mut _mutable_integer = 7i32;
    {
        // Borrow 
        let large_integer = &_mutable_integer;

        // Error! _mutable_integer is frozen in this scope
        // _mutable_integer = 50;

        println!("Immutably borrowed {}", large_integer);

        // `large_integer` goes out of scope
    }

    // Ok! `_mutable_integer` is not frozen in this scope
    _mutable_integer = 3;
}