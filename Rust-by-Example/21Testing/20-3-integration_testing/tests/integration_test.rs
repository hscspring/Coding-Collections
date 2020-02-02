// extern crate we're testing, same as any other code will do.
extern crate adder;

// importing common module.
mod common;

#[test]
fn test_add() {
    // using common code.
    common::setup();
    assert_eq!(adder::add(3, 2), 5);
}