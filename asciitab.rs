use std::clone::Clone;
use std::marker::Copy;

struct CharTab<T: Clone> {
    data: [T; 256],
}

impl<T: Clone + Copy> CharTab<T> {
    fn filled_with(val: T) -> CharTab<T> {
        CharTab{ data: [val; 256] }
    }
    fn get(&self, idx: char) -> T {
        return self.data[idx as usize];
    }
}

fn main() {
    let t = CharTab::filled_with('0' as u8);
    println!("{}", t.get('0') as char);
}
