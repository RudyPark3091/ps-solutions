use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    stdin.lock().read_line(&mut buf).unwrap();
    stdin.lock().read_line(&mut buf).unwrap();

    let v: Vec<i64> = buf.split_whitespace()
        .map(|x| x.parse().unwrap()).collect();
    let (w, h, p, q, t) = (v[0], v[1], v[2], v[3], v[4]);

    let mx = (p + t) % (w * 2);
    let my = (q + t) % (h * 2);
    let rx = mx >= w;
    let ry = my >= h;
    let x = if rx { w - (mx % w) } else { mx % w };
    let y = if ry { h - (my % h) } else { my % h };
    println!("{} {}", x, y);
}
