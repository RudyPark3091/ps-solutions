function bin(n) {
  let b = "";
  while (n > 0) {
    b += (n % 2).toString();
    n = Math.floor(n / 2);
  }
  return b;
}

function solution(n) {
  let ans = n + 1;
  const ones = x => bin(x).split('').filter(c => c === "1").length;
  while (ones(ans) !== ones(n))
    ans++;
  return ans;
}

