function solution(expression) {
  let answer = 0;

  const ops = [
    ['+', '-', '*'],
    ['+', '*', '-'],
    ['-', '+', '*'],
    ['-', '*', '+'],
    ['*', '+', '-'],
    ['*', '-', '+'],
  ];
  const fn = {
    '+': (x, y) => x + y,
    '-': (x, y) => x - y,
    '*': (x, y) => x * y,
  };

  const tokens = expression.split(/([+\-*])/);
  ops.forEach((order) => {
    const _tokens = Array.from(tokens);
    for (let i = 0; i < 3; i++) {
      const op = order[i];
      for (let i = 0; i < _tokens.length; i++) {
        if (_tokens[i] === op) {
          const x = parseInt(_tokens[i - 1]);
          const y = parseInt(_tokens[i + 1]);
          const val = fn[op] (x, y);
          _tokens.splice(i - 1, 3, val);
          i = 0;
        }
      }
    }
    answer = Math.max(answer, Math.abs(_tokens[0]));
  });
  return answer;
}

console.log(solution("100-200*300-500+20"));
