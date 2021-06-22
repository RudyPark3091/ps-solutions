function solution(n) {
  const arr = new Array(n).fill(true);
  arr[0] = false;
  for (let i = 2; i <= n; i++) {
    for (let j = 2; i * j <= n; j++) arr[i * j - 1] = false;
  }
  return arr.filter(v => v).length;
}

