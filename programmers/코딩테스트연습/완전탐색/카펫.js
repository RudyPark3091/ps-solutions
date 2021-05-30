function solution(brown, yellow) {
  const div = (y, x) => y % x === 0;
  for (let i = 1; i <= yellow; i++) {
    if (!div(yellow, i)) continue;
    const a = i;
    const b = yellow / i;
    if (a + b + 4 === brown) return [b + 2, a + 2];
  }
}
