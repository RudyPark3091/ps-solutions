use std::io::{self, Read};

fn f(v: &mut Vec<Vec<char>>, n: usize, limit: usize) {
    if n >= limit {
        return;
    }
    let l = v.len();

    for i in n..l - n {
        v[n][i] = '*';
        v[l - n - 1][i] = '*';
        v[i][n] = '*';
        v[i][l - n - 1] = '*';
    }

    f(v, n + 2, limit);
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_to_string(&mut buf).unwrap();
    let n: usize = buf.trim().parse().unwrap();

    let mut pxl = vec![vec![' '; 4 * n - 3]; 4 * n - 3];
    f(&mut pxl, 0, 2 * n - 1);
    for row in pxl {
        let mut s = String::new();
        for c in row {
            s.push(c);
        }
        println!("{}", s);
    }
}
