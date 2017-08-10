const BUF_SIZE: i32 = 1024;
const TICK_SIZE: i32 = 4000;

fn fill(from: i32, to: i32) -> Vec<i32> {
    println!("Filling: {} to {}", from, to);
    let mut samples = Vec::with_capacity((to - from) as usize);
    for i in from..to {
        samples.push(i);
    }
    samples
}

fn fill_range(mut at: i32) -> Vec<i32> {
    let mut samples = Vec::with_capacity(BUF_SIZE as usize);
    let wanted = at + BUF_SIZE - 1;
    while at < wanted {
        let next_at = std::cmp::min((
            (at / TICK_SIZE + 1) * TICK_SIZE), wanted);
        samples.append(&mut fill(at, next_at));
        at = next_at;
    }
    println!("-- next --");
    samples
}

fn main() {
    let mut at = 0;
    for _ in 0..100 {
        fill_range(at);
        at += BUF_SIZE;
    }
}
