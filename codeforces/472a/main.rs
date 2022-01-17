use std::io::{self, Read};

fn is_prime(x: i32) -> bool {
    for i in 2..=((x as f32).sqrt() as i32) {
        if x % i == 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_to_string(&mut buf).unwrap();
    let n: i32 = buf.trim().parse().unwrap();

    for i in 4..n {
        let p1 = is_prime(i);
        let p2 = is_prime(n - i);
        if !p1 && !p2 {
            println!("{} {}", i, n - i);
            break;
        }
    }
}
