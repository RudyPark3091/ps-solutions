function solution(number, k) {
  const arr = number.split('').map(n => n.toString());
  let del = 0;

  let s = [];
  const empty = st => st.length === 0;
  const top = st => st[st.length - 1];

  for (const n of arr) {
    while (!empty(s) && top(s) < parseInt(n)) {
      if (del < k) {
        s.pop();
        del++;
      } else {
        break;
      }
    }
    s.push(parseInt(n));
  }

  if (del < k) {
    for (let i = 0; i < k - del; i++) s.pop();
  }
  return s.join('');
}

console.log(solution("1924", 2))
console.log(solution("1231234", 3))
console.log(solution("4177252841", 4))
console.log(solution("123456", 3))
console.log(solution("654321", 3))
