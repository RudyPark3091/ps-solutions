function solution(land) {
  const n = land.length;
  const dp = Array.from(new Array(n), () => new Array(4).fill(0));

  for (let i = 0; i < 4; i++)
    dp[0][i] = land[0][i];

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < 4; j++) {
      const max = Math.max(...dp[i - 1].slice(0, j).concat(...dp[i - 1].slice(j + 1)));
      dp[i][j] = max + land[i][j];
    }
  }

  return Math.max(...dp[n - 1]);
}

console.log(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]));
