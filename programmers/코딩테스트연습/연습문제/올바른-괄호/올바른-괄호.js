function solution(s) {
  let answer = true;
  const stack = [];
  s.split('').forEach(ch => {
    if (!answer)
      return;

    if (ch === "(")
      stack.push("(");
    else if (ch === ")" && stack[stack.length - 1] !== "(")
      answer = false;
    else if (ch === ")" && stack[stack.length - 1] === "(")
      stack.pop();
  });
  return stack.length === 0 ? answer : false;
}

