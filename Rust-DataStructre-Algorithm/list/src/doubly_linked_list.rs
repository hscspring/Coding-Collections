use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, Clone)]
struct Node {
    value: String,
    next: Link,
    prev: Link,
}

type Link = Option<Rc<RefCell<Node>>>;

pub struct ListIterator {
    current: Link,
}

impl ListIterator {
    fn new(start_at: Link) -> ListIterator {
        ListIterator {
            current: start_at,
        }
    }
}

impl Iterator for ListIterator {
    type Item = String;
    fn next(&mut self) -> Option<String> {
        let current = &self.current;
        let mut result = None;
        self.current = match current {
            Some(ref current) => {
                let current = current.borrow();
                result = Some(current.value.clone());
                current.next.clone()
            },
            None => None
        };
        result
    }


impl DoubleEndedIterator for ListIterator {
    fn next_back(&mut self) -> Option<String> {
        let current = &self.current;
        let mut result = None;
        self.current = match current {
            Some(ref current) => {
                let current = current.borrow();
                result = Some(current.value.clone());
                current.prev.clone()
            },
            None => None
        };
        result
    }
}