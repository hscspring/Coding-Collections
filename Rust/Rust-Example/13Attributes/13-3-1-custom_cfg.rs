// rustc --cfg some_condition 13custom_cfg.rs && ./13custom_cfg

#[cfg(some_condition)]
fn conditional_function() {
    println!("condition met!");
}

fn main() {
    conditional_function();
}
