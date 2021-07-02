const [n, m] = require('fs')
  .readFileSync('/dev/stdin')
  .toString()
  .split(' ')
  .map(x => parseInt(x));
let ans = "";
permutator(Array.from(new Array(n), (_, i) => i + 1), m)
  .map(arr => ans += (arr.join(' ') + '\n'));
console.log(ans);

function permutator(target, _m) {
  const result = [];

  const permute = (arr, m = []) => {
    if (m.length === _m) {
      result.push(m);
    } else {
      for (let i = 0; i < arr.length; i++) {
        const _arr = Array.from(arr);
        const next = _arr.splice(i, 1);
        permute(Array.from(_arr), m.concat(next));
      }
    }
  };

  permute(target);
  return result;
}
