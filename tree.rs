trait Writer {
    fn write(&self);
}

struct Node<T: Writer> {
    writer: T,
    sub: Vec<Node>,
}
impl<T: Writer> Node<T> {
    fn write(&self) {
        for child in &self.sub {
            self.write();
        }
        self.writer.write();
    }
}

struct IdentWriter {
    name: &'static str
}
impl Writer for IdentWriter {
    fn write(&self) {
        println!("{}", self.name);
    }
}

fn main() {
    let piss = Node{
        writer: IdentWriter{ name: "hello, " },
        sub: vec!(Node{
            writer: IdentWriter{ name: "world" },
            sub: vec!(),
        })
    };

    piss.write();
}
