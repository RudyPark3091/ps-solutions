function search(n, graph) {
  const visited = new Array(n).fill(false);
  const dists = new Array(n).fill(0);
  const q = [];

  visited[0] = true;
  q.push(0);

  while (q.length !== 0) {
    const now = q.shift();
    graph[now].forEach(v => {
      if (visited[v]) return;
      q.push(v);
      visited[v] = true;
      dists[v] = dists[now] + 1;
    });
  }
  return dists.map((d, i) => [d, i]);
}

function solution(n, edge) {
  const graph = Array.from(new Array(n), () => []);
  edge.forEach(pair => {
    graph[pair[0] - 1].push(pair[1] - 1);
    graph[pair[1] - 1].push(pair[0] - 1);
  });

  const res = search(n, graph);
  return res
    .filter(pair => pair[0] === Math.max(...res.map(p => p[0])))
    .map(p => p[1] + 1)
    .length;
}
