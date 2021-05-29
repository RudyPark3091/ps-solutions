function permutator(target) {
  const result = [];

  const permute = (arr, m = []) => {
    if (arr.length === 0) {
      result.push(m);
    } else {
      for (let i = 0; i < arr.length; i++) {
        const current = Array.from(arr);
        const next = current.splice(i, 1);
        permute(Array.from(current), m.concat(next));
      }
    }
  };

  permute(target);
  return result;
}

function isPrime(n) {
  if (n < 2) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}

function solution(numbers) {
  const permuted = permutator(numbers.split("").concat(" ".repeat(numbers.length)));
  const nums = new Set(permuted.map((p) => parseInt(p.join("").trim())));
  return Array.from(nums).filter((n) => (isPrime(n) ? true : false)).length;
}

