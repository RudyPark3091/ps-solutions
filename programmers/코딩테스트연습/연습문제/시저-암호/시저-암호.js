function solution(s, n) {
  const upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const lower = "abcdefghijklmnopqrstuvwxyz";
  return s
    .split('')
    .map(c => {
      if (c === ' ')
        return ' ';
      else {
        const arr = upper.includes(c) ? upper : lower;
        return arr[(arr.indexOf(c) + n) % 26];
      }
    })
    .join('');
}
