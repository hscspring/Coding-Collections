fn reset(arr: &mut [u32]) {
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    println!("array length {:?}", arr.len());
    println!("reset array {:?}", arr);
}

enum Void {}

fn main() {
    println!("Hello, world!");
    let mut arr = [1, 2, 3, 4, 5];
    println!("reset before: origin array {:?}", arr);
    {
        let mut_arr: &mut[u32] = &mut arr;
        reset(mut_arr);
    }
    println!("reset after: origin array {:?}", arr);


    let res: Result<u32, Void> = Ok(0);
    let Ok(num) = res;
}
