use std::io::{self, BufRead};

fn mark(board: &mut Vec<Vec<i32>>, t: i32) {
    for i in 0..board.len() {
        for j in 0..board[i].len() {
            if board[i][j] == t {
                board[i][j] = 0;
            }
        }
    }
}

fn check(board: Vec<Vec<i32>>) -> bool {
    let mut cnt = 0;
    for i in 0..5 {
        if board[i] == vec![0, 0, 0, 0, 0] {
            cnt += 1;
        }
    }
    for i in 0..5 {
        let mut row = 0;
        for j in 0..5 {
            if board[j][i] == 0 {
                row += 1;
            }
        }
        if row == 5 {
            cnt += 1;
        }
    }
    let mut dgn = 0;
    for i in 0..5 {
        if board[i][i] == 0 {
            dgn += 1;
        }
    }
    if dgn == 5 {
        cnt += 1;
    }
    let mut _dgn = 0;
    for i in 0..5 {
        if board[4 - i][i] == 0 {
            _dgn += 1;
        }
    }
    if _dgn == 5 {
        cnt += 1;
    }
    return cnt >= 3;
}

fn from_buf(buf: &String) -> Vec<Vec<i32>> {
    let v = buf
        .clone()
        .trim()
        .split("\n")
        .map(|x| x.to_string())
        .map(|s| s.split_whitespace().map(|x| x.parse().unwrap()).collect::<Vec<i32>>())
        .collect::<Vec<Vec<i32>>>();
    v
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    for _ in 0..5 {
        stdin.lock().read_line(&mut buf).unwrap();
    }
    let mut board = from_buf(&buf);
    buf.clear();

    for _ in 0..5 {
        stdin.lock().read_line(&mut buf).unwrap();
    }
    let call = from_buf(&buf);

    let mut ans = 1;
    for row in &call {
        for num in row {
            mark(&mut board, *num);
            let bingo = check(board.to_vec());
            if bingo {
                println!("{}", ans);
                return;
            }
            ans += 1;
        }
    }
}
