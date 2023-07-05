function solution(players, callings) {
  const _players = {};
  for (let i = 0; i < players.length; i++) {
    _players[players[i]] = i;
  }

  callings.forEach((name) => {
    const rank = _players[name];
    const targetName = players[rank - 1];
    players[rank - 1] = name;
    players[rank] = targetName;
    _players[name] -= 1;
    _players[targetName] += 1;
  });

  return players;
}
