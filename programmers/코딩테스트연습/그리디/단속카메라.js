function solution(routes) {
  let ans = 1;
  routes.sort((a, b) => a[0] - b[0]);
  let cmp = routes[0][1];
  routes.forEach((_, i) => {
    if (i === routes.length - 1) return;
    if (routes[i][1] < cmp) cmp = routes[i][1];
    if (routes[i + 1][0] > cmp) {
      ans += 1;
      cmp = routes[i + 1][1];
    }
  });
  return ans;
}

console.log(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]]));
