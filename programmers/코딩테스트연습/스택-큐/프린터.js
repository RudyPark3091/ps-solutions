function solution(priorities, location) {
  let ans = 0;
  const loop = (arr) => {
    if (arr.length !== 1 && Math.max(...(arr.slice(1).map(p => p[0]))) > arr[0][0]) {
      loop(arr.slice(1).concat([arr[0]]));
    } else {
      ans++;
      if (arr[0][1] === location) return;
      return loop(arr.slice(1));
    }
  }

  loop(priorities.map((item, i) => [item, i]));
  return ans;
}
