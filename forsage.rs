fn main() {
    let list: Vec<_> = std::iter::repeat(())
        .take(100)
        .enumerate()
        .map(|s| {s.0 as i32})
        .collect();
    for num in list {
        println!("{}", num);
    }
}
