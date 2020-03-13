/* Objects and behavior

class Door {
    private bool is_open = false;
    
    public void Open() {
        this.is_open = true;
    }
}
*/


struct Door {
    is_open: bool
}

#[allow(dead_code)]
impl Door {
    fn new(is_open: bool) -> Door {
        Door { is_open: is_open }
    }
}

trait Openable {
    fn open(&mut self);
}

impl Openable for Door {
    fn open(&mut self) {
        self.is_open = true;
    }
}


fn main() {
    /*  Wrong  */

    use std::io;

    // Option<T> or Result<T, E>
    fn find(_needle: u16, _haystack: Vec<u16>) -> Option<usize> { Some(2) }
    fn read_file(_path: &str) -> Result<String, io::Error> {
        Ok("xx".to_string())
    }
    // handle with match or if let
    match find(2, vec![1,2,3,4]) {
        Some(num) => println!("{:?}", num),
        None => println!("not found"),
    }
    if let Some(_num) = find(2, vec![1,3,4]) { println!("found") }

    match read_file("file/path") {
        Ok(cont) => println!("{:?}", cont),
        Err(_err) => println!("error"),
    }

    /* Lifetime */

    let mut a = 42;
    let _b = &a; // immutable borrow
    let _c = &mut a; // mutable borrow
    // let _d = b; // cannot use b
    let e = &mut a;

    println!("{:?}", e);

    let x = vec![1, 2, 3];
    let y = &x;
    let xx = x.clone();
    let yy = y.clone();

    println!("{:?}", x);
    println!("{:?}", xx);
    println!("{:?}", y);
    println!("{:?}", yy);


    /* Multiple owners */

    use std::rc::Rc;

    #[derive(Debug)]
    struct FileName {
        name: Rc<String>,
        ext: Rc<String>
    }

    fn no_ref_counter() {
        let name = Rc::new(String::from("Main"));
        let ext = Rc::new(String::from("rs"));

        for _ in 0..3 {
            println!("{:?}", FileName {
                name: name.clone(),
                ext: ext.clone()
            });
        }
    }

    no_ref_counter();


    /* Concurrency and mutability */

    use std::thread;

    #[allow(dead_code)]
    fn threading() {
        let handle = thread::spawn(|| {
            println!("Hello from a thread");
        });
        handle.join().unwrap();
    }

    /* Shadowing */

    #[allow(dead_code)]
    fn sanitize(s: String) -> String {
        let s = s.trim();
        let s = s.replace(" ", "_");
        s
    }

    /* Interior mutability */

    use std::cell::RefCell;

    #[derive(Clone)]
    struct Node {
        value: String,
        next: Link,
        prev: Link,
    }

    type Link = Option<Rc<RefCell<Node>>>;

    /*
    pub fn append(&mut self, value: String) {
        let new = Rc::new(RefCell::new(Node::new(value)));
        match self.tail.take() {
            Some(old) => {
                old.borrow_mut().next = Some(new.clone());
                new.borrow_mut().prev = Some(old);

            },
            None => self.head = Some(new.clone()),
        };
    }
    */


    /* Moving data */

    fn threading_again() {
        let x = 10;
        let handle = thread::spawn(move || {
            println!("Hello from a thread, the number is {}", x);
        });
        handle.join().unwrap();
    }

    threading_again();

    use std::sync::mpsc::{channel, Sender, Receiver};

    fn channels() {
        const N: i32 = 10;
        let (tx, rx): (Sender<i32>, Receiver<i32>) = channel();
        
        let handles = (0..N).map(|i| {
            let _tx = tx.clone();
            thread::spawn(move || {
                let _ = _tx.send(i).unwrap();
            })
        });
        // close all threads
        for h in handles {
            h.join().unwrap();
        }
        // receive N times
        let numbers: Vec<i32> = (0..N).map(|_| 
            rx.recv().unwrap()
        ).collect();

        println!("{:?}", numbers);
    }

    channels();


    /* Sharing data */

    use std::sync::{Mutex, Arc};

    fn share_state() {
        let v = Arc::new(Mutex::new(vec![]));
        
        let handles = (0..10).map(|i| {
            let numbers = Arc::clone(&v);
            thread::spawn(move || {
                let mut vector = numbers
                    .lock()
                    .unwrap();
                (*vector).push(i);
            })
        });

        for handle in handles {
            handle.join().unwrap();
        }

        println!("{:?}", *v.lock().unwrap());
    }

    share_state();


    //#####Chapter3 Storing Efficiently#####//

    /* Heaps and stacks */

    use std::mem;

    #[allow(dead_code)]
    struct MyStruct {
        a: u8,
        b: u8,
        c: u8
    }

    assert_eq!(mem::size_of::<MyStruct>(), 
        3 * mem::size_of::<u8>());
    assert_eq!(mem::size_of::<[MyStruct; 2]>(), 
        6 * mem::size_of::<u8>());


    /* Generics */

    /* 
    fn my_generic_func<T: MyTrait>(t: T) {}
    // is the same as
    fn my_generic_func<T>(t: T) where T: MyTrait {}
    // better use in 2018
    fn my_generic_func(t: impl MyTrait) {}
    

    fn my_generic_func<T>(t: T) {}
    // the same as
    fn my_generic_func<T: Sized>(t: T) {}


    fn my_generic_func<T: ?Sized>(t: &T) {}

    */


    /* Copying and cloning */

    let x = 5;
    let _y = x; // Copy

    let a = Rc::new(5);
    let _b = a.clone(); // Clone
    let _c = a;

}

