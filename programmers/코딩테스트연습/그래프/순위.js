function solution(n, results) {
  const graph = Array.from(new Array(n + 1), () => new Array(n + 1).fill(false));
  results.forEach(([a, b]) => graph[a][b] = true);

  for (let k = 1; k <= n; k++) {
    for (let i = 1; i <= n; i++) {
      for (let j = 1; j <= n; j++) {
        if (graph[i][k] && graph[k][j]) graph[i][j] = true;
      }
    }
  }

  let ans = 0;
  graph.forEach((row, i) => {
    if (i === 0) return;
    let cnt = 0;
    row.forEach((val, j) => cnt += (val || graph[j][i]) ? 1 : 0);
    ans += (cnt === n - 1) ? 1 : 0;
  });
  return ans;
}
