function solution(people, limit) {
  const arr = Array.from(people).sort((a, b) => b - a);
  let l = 0;
  let r = arr.length - 1;
  let ans = 0;

  while (l < r) {
    if (arr[l] + arr[r] <= limit) r--;
    l++; ans++;
  }

  return ans + (l === r ? 1 : 0);
}
