#[allow(dead_code)]

struct Stack {
    cap: usize,
    collection: Vec<i32>,
    size: usize,
}


impl Stack {
    
    pub fn new(cap: usize) -> Self {
       Self {
        size: 0,
        cap: cap,
        collection: vec![0; cap],

       }
    } 

    pub fn push(&mut self, item:i32) -> bool {
        if self.is_full() {
            return false;
        }

        self.collection[self.size] = item;
        self.size +=1;
        return true;
    }    

    pub fn peek(&self) -> Option<i32> {
        if self.is_empty() {
            return None;
        }
        return Some(self.collection[self.size-1])
    }

    pub fn pop(&mut self) -> Option<i32> {
        if self.is_empty() {
            return None;
        }
        self.size -=1;
        return Some(self.collection[self.size])
    }

    pub fn is_full(&self) -> bool {
        return self.size == self.cap
    }

    pub fn is_empty(&self) -> bool {
        return self.size == 0
    }

}


fn main() {
    let mut stack = Stack::new(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    println!("{:?}", stack.peek()); 
    println!("{:?}", stack.pop());  
    println!("{:?}", stack.pop());  

    println!("{}", stack.is_empty()); 
    println!("{}", stack.is_full());  

    drop(stack);
}
