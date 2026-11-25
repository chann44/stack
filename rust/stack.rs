#![allow(dead_code)]

struct Stack {
    cap: u32,
    collection: Vec<u32>,
    size: u32,
}


impl Stack {
    
    fn new(cap: u32) -> Self {
       Self {
        size: 0;
       }
    } 

    fn push(&self, item:u32) -> bool {
        return true 
    }    

    fn pop(&self) -> u32 {

        return 0
    }

    fn is_full(&self) -> bool {

        return true 
    }

    fn is_empty(&self) -> bool {
        return true 
    }

}


fn main() {
    println!("hello world "); 
}
