const input = require('fs').readFileSync('/dev/stdin').toString();
const [n, m] = input.split(' ').map(x => parseInt(x));
const ans = solution(Array.from(new Array(n), (_, i) => i + 1), m);
console.log(ans.map(arr => arr.join(' ')).join('\n'));

function solution(target, _m) {
  const result = [];

  const solve = (arr, acc = []) => {
    if (acc.length === _m) {
      result.push(acc);
    } else {
      for (let i = 0; i < target.length; i++) {
        const _arr = Array.from(arr);
        const next = target[i];
        if (acc.length === 0 || next >= acc[acc.length - 1])
          solve(_arr, acc.concat(target[i]));
      }
    }
  }

  solve(target);
  return result;
}
