const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on('line', (line) => {
  let ans = "";
  const [n, m] = line.split(' ').map(x => parseInt(x));
  permutator(Array.from(new Array(n), (_, i) => i + 1), m)
    .forEach(arr => ans += (arr.join(' ') + '\n'));
  console.log(ans);
});

function permutator(target, m) {
  const result = [];

  const permute = (arr, acc = []) => {
    if (acc.length === m) {
      result.push(acc);
    } else {
      for (let i = 0; i < arr.length; i++) {
        const _arr = Array.from(arr);
        const next = _arr.splice(i, 1);
        if (acc.length === 0 || next > acc[acc.length - 1]) {
          permute(_arr, acc.concat(next));
        }
      }
    }
  }

  permute(target);
  return result;
}
