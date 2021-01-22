function bfs(x, computers, visited) {
	let res = false;
	let q = [];
	if (!visited[x]) {
		visited[x] = true;
		q.push(x);
		res = true;
	}

	while (q.length !== 0) {
		const now = q[0];
		q = q.slice(1);

		for (let i = 0; i < computers.length; i++) {
			if (!visited[i] && computers[now][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return res;
}

function solution(n, computers) {
	var answer = 0;

	let visited = new Array(n).fill(false);
	for (let i = 0; i < n; i++) {
		if (bfs(i, computers, visited)) {
			answer++;
		}
	}

	return answer;
}

console.log(
	solution(3, [
		[1, 1, 0],
		[1, 1, 1],
		[0, 1, 1],
	])
);
