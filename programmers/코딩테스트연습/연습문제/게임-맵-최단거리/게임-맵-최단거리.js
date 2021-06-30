function solution(maps) {
  const n = maps.length;
  const m = maps[0].length;

  const moves = [[1, 0], [0, 1], [-1, 0], [0, -1]];
  const q = [];
  const visited = Array.from(new Array(n), () => new Array(m).fill(false));

  visited[0][0] = true;
  q.push([0, 0, 1]);

  while (q.length !== 0) {
    const now = q.shift();
    if (now[0] == n - 1 && now[1] == m - 1)
      return now[2];
    for (let i = 0; i < 4; i++) {
      const next = [now[0] + moves[i][0], now[1] + moves[i][1], now[2] + 1];
      const bdry = 0 <= next[0] && next[0] < n && 0 <= next[1] && next[1] < m;
      if (!bdry)
        continue;
      if (!visited[next[0]][next[1]] && maps[next[0]][next[1]]) {
        q.push(next);
        visited[next[0]][next[1]] = true;
      }
    }
  }

  return -1;
}

console.log(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))
