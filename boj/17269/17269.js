const input = require("fs").readFileSync("/dev/stdin").toString();

const idx = (char) => char.charCodeAt(0) - "A".charCodeAt(0);
const nums = [
  3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1,
];

const [N, M, a, b] = input.split("\n").flatMap((xs) => xs.split(" "));
const n = parseInt(N);
const m = parseInt(M);

let str = "";
for (let i = 0; i < Math.min(n, m); i++) {
  str += a[i] + b[i];
}
str += n < m ? b.slice(n) : a.slice(m);
const res = str.split("").map((x) => nums[idx(x)]);

for (let i = 0; i < res.length - 2; i++) {
  for (let j = 1; j < res.length - i; j++) {
    res[j - 1] = (res[j - 1] + res[j]) % 10;
  }
}
const ans = res[0].toString() + res[1].toString();
console.log(`${parseInt(ans)}%`);
