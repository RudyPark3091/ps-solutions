use std::io;
use std::io::Write;

fn d(mut n: usize) -> usize {
    let mut sum = n;
    while n > 0 {
        sum += n % 10;
        n /= 10;
    }
    sum
}

fn main() {
    let stdout = io::stdout();
    let mut output = io::BufWriter::new(stdout.lock());

    let mut is_self = vec![true; 10000];
    for i in 1..=10000 {
        let idx = d(i);
        if idx < 10000 {
            is_self[idx] = false;
        }
    }

    is_self.iter().skip(1).enumerate().for_each(|(i, x)| {
        if *x {
            writeln!(output, "{}", i + 1).unwrap();
        }
    });
}
