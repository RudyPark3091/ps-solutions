function solution(n) {
  const num = [1, 2, 4];
  const ans = [];
  while (n > 0) {
    n -= 1;
    ans.push(num[n % 3]);
    n = Math.floor(n / 3);
  }

  return ans.reverse().join('');
}

