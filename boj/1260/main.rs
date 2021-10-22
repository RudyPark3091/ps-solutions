use std::io::{self, BufRead};
use std::collections::VecDeque;

static mut VISITED: [bool; 1001] = [false; 1001];
static mut GRAPH: [[bool; 1001]; 1001] = [[false; 1001]; 1001];

fn main() {
    let edges = input();
    let (n, v) = (edges[0][0], edges[0][2]);
    unsafe { GRAPH = [[false; 1001]; 1001]; }

    for edge in edges.into_iter().skip(1) {
        let x = edge[0] as usize;
        let y = edge[1] as usize;
        unsafe {
            GRAPH[x][y] = true;
            GRAPH[y][x] = true;
        }
    }

    unsafe {
        dfs(n as usize, v as usize);
        println!("");
        VISITED = [false; 1001];
        bfs(n as usize, v as usize);
        println!("");
    }
}

fn input() -> Vec<Vec<i32>> {
    let stdin = io::stdin();
    stdin
        .lock()
        .lines()
        .map(|l| {
            l.unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect::<Vec<Vec<i32>>>()
}

unsafe fn dfs(n: usize, node: usize) {
    print!("{} ", node);
    VISITED[node] = true;
    for i in 1..=n {
        if !VISITED[i] && GRAPH[node][i] {
            dfs(n, i);
        }
    }
}

unsafe fn bfs(n: usize, node: usize) {
    let mut queue = VecDeque::new();
    VISITED[node] = true;
    queue.push_back(node);

    while queue.len() != 0 {
        if let Some(next) = queue.pop_front() {
            print!("{} ", next);

            for i in 1..=n {
                if !VISITED[i] && GRAPH[next][i] {
                    queue.push_back(i);
                    VISITED[i] = true;
                }
            }
        }
    }
}
