fn printhex(hex: u32) {
    for i in (0..8).rev() {
        print!("{:X}", (hex>>i*4) & 0xf);
    }
    println!("");
}
fn main() {
    let hex = 0xff;
    let mut dec = hex;
    for i in (0..8).rev() {
        if dec>>i*4 & 0xf > 9 {
            dec += 6<<(i*4);
        }
    }
    printhex(hex);
    printhex(dec);
}
