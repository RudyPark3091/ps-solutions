use std::io::{self, BufRead, Write};

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap())
        .for_each(|x| {
            let mut yes = true;
            let mut s = vec![];
            for c in x.chars() {
                if c == '(' {
                    s.push(true);
                } else {
                    if s.len() != 0 && *s.last().unwrap() == true {
                        s.pop();
                    } else {
                        yes = false;
                        break;
                    }
                }
            }
            if s.len() == 0 && yes {
                writeln!(out, "YES").unwrap();
            } else {
                writeln!(out, "NO").unwrap();
            }
        });
}
