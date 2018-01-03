type PhantomInt = i32;

fn print(i: PhantomInt) {
    println!("{}", i);
}
fn main() {
    let pi: PhantomInt = 1;
    print(pi);
    let i = 1;
    print(i);
}
