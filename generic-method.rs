struct Hello {
    times: i32,
}

impl Hello {
    fn print<T: std::fmt::Display>(&self, value: T) {
        for _ in 0 .. self.times {
            value.fmt();
        }
    }
}

fn main() {
    let h = Hello{ times: 2 };
    h.print("cool");
    h.print(11);
}
