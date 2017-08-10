trait Integer {
    fn min_value() -> Self;
    fn max_value() -> Self;
}
trait MinMax {
    fn min(self, other: Self) -> Self;
    fn max(self, other: Self) -> Self;
}

fn clip<I: Integer + From<F>, F: MinMax + From<I>>(f: F) -> I {
    let min = F::from(I::min_value());
    let max = F::from(I::max_value());
    I::from(f.max(min).min(max))
}

fn main() {
    let num = 256.0_f32;
    println!("{}", clip::<u8, f32>(num));
    println!("{}", num
             .min(std::u8::MAX as f32)
             .max(std::u8::MIN as f32) as u8);
}
