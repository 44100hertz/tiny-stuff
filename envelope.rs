fn clamp(a: f64) -> f64 { a.max(0.0).min(1.0) }
fn lerp(a: f64, b: f64, thru: f64) -> f64 { a*thru + b*(1.0-thru) }

trait Env {
    fn get(&self, pos: f64) -> f64;
}

struct Point { x: f64, y: f64, }

struct PointEnv {
    data: Vec<Point>,
}
impl Env for PointEnv {
    fn get(&self, pos: f64) -> f64 {
        let mut i = 1usize;
        while self.data[i].x < pos && i < self.data.len()-1 { i+=1 }
        let p1 = &self.data[i-1];
        let p2 = &self.data[i];
        lerp(p1.y, p2.y, clamp((p2.x - pos) / (p2.x - p1.x)))
    }
}
impl PointEnv {
    fn to_list(&self) -> ListEnv {
        let mut v = Vec::new();
        for i in 0..self.data.last().unwrap().x as usize {
            v.push(self.get(i as f64))
        }
        ListEnv{ data: v }
    }
}

struct ListEnv {
    data: Vec<f64>,
}
impl Env for ListEnv {
    fn get(&self, pos: f64) -> f64 {
        self.data[std::cmp::min(pos as usize, self.data.len()-1)]
    }
}

struct PolynomEnv {
    a: f64,
    b: f64,
    c: f64,
}
impl Env for PolynomEnv {
    fn get(&self, pos: f64) -> f64 {
        clamp(self.a + pos*self.b + pos*pos*self.c)
    }
}

fn try_env<E: Env>(env: &E) {
    println!("{}", env.get(0.0));
    println!("{}", env.get(5.0));
    println!("{}", env.get(10.0));
    println!("{}", env.get(15.0));
    println!("{}", env.get(20.0));
    println!("{}", env.get(25.0));
    println!("-------");
}

fn bench_env<E: Env>(env: &E) {
    for i in 0..10000 {
        env.get(i as f64*20.0/10000.0);
    }
}

fn main() {
    let p = PointEnv{data: vec!(
        Point{ x:0.0,  y:0.0 },
        Point{ x:10.0, y:1.0 },
        Point{ x:20.0, y:0.0 }
    )};
    let l = p.to_list();
    let pn = PolynomEnv {
        a: 0.0,
        b: 20.0/100.0,
        c: -1.0/100.0,
    };
    try_env(&p);
    try_env(&l);
    try_env(&pn);
    bench_env(&p);
    bench_env(&l);
    bench_env(&pn);
}
