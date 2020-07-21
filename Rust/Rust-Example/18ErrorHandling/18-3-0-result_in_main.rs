use std::num::ParseIntError;

fn main() -> Result<(), ParseIntError> {
    let num_str = "10";

    let num = match num_str.parse::<i32>() {
        Ok(num) => num,
        Err(e) => return Err(e),
    };

    println!("{}", num);
    Ok(())
}