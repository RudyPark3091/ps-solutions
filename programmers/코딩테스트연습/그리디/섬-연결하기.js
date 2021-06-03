function solution(n, costs) {
  const arr = Array.from(costs).sort((a, b) => a[2] - b[2]);
  const parent = Array.from(new Array(n), (_, i) => i);
  const findParent = x => {
    if (parent[x] !== x) parent[x] = findParent(parent[x]);
    return parent[x];
  }
  const union = (x, y) => {
    const a = findParent(x);
    const b = findParent(y);
    if (a > b) parent[a] = b;
    else parent[b] = a;
  }

  let ans = 0;
  arr.forEach((item) => {
    const a = item[0];
    const b = item[1];
    const cost = item[2];

    if (findParent(a) !== findParent(b)) {
      union(a, b);
      ans += cost;
    }
  });
  return ans;
}

