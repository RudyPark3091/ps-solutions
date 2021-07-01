function check(s) {
  const stack = [];

  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (c === "(" || c === "[" || c === "{") {
      stack.push(c);
    } else if (
      (c === ")" && stack[stack.length - 1] !== "(") ||
      (c === "]" && stack[stack.length - 1] !== "[") ||
      (c === "}" && stack[stack.length - 1] !== "{")
    ) {
      return false;
    } else {
      stack.pop();
    }
  }

  return stack.length === 0;
}

function solution(s) {
  let ans = 0;
  let _s = s;

  for (let i = 0; i < s.length; i++) {
    if (check(_s)) ans++;
    _s = _s.substring(1) + _s[0];
    console.log(_s);
  }

  return ans;
}

console.log(solution("[](){}"));
