use std::io::{self, BufRead};

macro_rules! read_string {
    () => {{
        let stdin = io::stdin();
        let mut buf = String::new();
        stdin.lock().read_line(&mut buf).unwrap();
        buf.truncate(buf.len() - 1);
        buf
    }};
}

macro_rules! read_int {
    () => {{
        let s = read_string!();
        let n: i32 = s.parse().unwrap();
        n
    }};
}

fn solve() -> [Vec<char>; 3] {
    let mut board: [Vec<char>; 3] = Default::default();
    for i in 0..3 {
        board[i] = read_string!().chars().collect();
    }
    let mark = read_string!().chars().nth(0).unwrap();
    let no = if mark == 'x' { 'o' } else { 'x' };

    for i in 0..3 {
        let mut n = 0;
        for j in 0..3 {
            if board[i][j] == mark { n += 1;}
            else if board[i][j] == no { n -= 1; }
        }
        if n == 2 {
            board[i] = vec![mark, mark, mark];
            return board;
        }
    }

    for i in 0..3 {
        let mut n = 0;
        for j in 0..3 {
            if board[j][i] == mark { n += 1; }
        }
        if n == 2 {
            for j in 0..3 { board[j][i] = mark; }
            return board;
        }
    }

    let n = vec![board[0][0], board[1][1], board[2][2]].iter()
        .filter(|&&x| x == mark).count();
    if n == 2 {
        for i in 0..3 { board[i][i] = mark; }
    }
    let n = vec![board[0][2], board[1][1], board[2][0]].iter()
        .filter(|&&x| x == mark).count();
    if n == 2 {
        for i in 0..3 { board[i][2 - i] = mark; }
    }
    return board;
}

fn main() {
    let s = read_int!();
    for i in 0..s {
        let arr = solve();
        println!("Case {}:", i + 1);
        for row in arr {
            println!("{}{}{}", row[0], row[1], row[2]);
        }
    }
}
