// occurs runtime error due to god damn recursion depth issue of programmers
function solution(l, weight, truck_weights) {
  let ans = 0;
  const loop = (onBridge, t, remains) => {
    if (onBridge.length === 0 && remains.length === 0) return;
    ans++;
    const still = onBridge.filter(truck => truck[1] > t);
    const more = still
      .map(truck => truck[0])
      .reduce((a, c) => a + c, 0) + remains[0] <= weight;
    loop (
      more ? still.concat([[remains[0], t + l]]) : still,
      t + 1,
      more ? remains.slice(1) : remains
    );
  }

  loop ([], 0, truck_weights);
  return ans;
}

// same logic but with while loop
function _solution(l, weight, truck_weights) {
  let ans = 0;
  let t = 0;
  let onBridge = [];
  let remains = truck_weights.slice(0);

  while (true) {
    if (onBridge.length === 0 && remains.length === 0) break;
    ans++;
    t++;
    const still = onBridge.filter(truck => truck[1] > t);
    const more = still
      .map(truck => truck[0])
      .reduce((a, c) => a + c, 0) + remains[0] <= weight;
    if (more) {
      onBridge = still.concat([[remains[0], t + l]]);
      remains = remains.slice(1);
    } else {
      onBridge = still;
    }
  }

  return ans;
}

