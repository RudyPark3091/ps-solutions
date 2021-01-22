function check(x, y) {
	let cnt = 0;
	const n = x.length;
	for (let i = 0; i < x.length; i++) {
		if (x[i] === y[i]) cnt++;
	}
	if (cnt === n - 1) return true;
	else return false;
}

function solution(begin, target, words) {
	const n = words.length;
	let flag = true;
	for (let i = 0; i < n; i++) {
		if (words[i] === target) flag = false;
	}
	if (flag) return 0;

	let visited = new Array(n).fill(false);

	let answer = 0;
	function dfs(w, depth) {
		if (w === target) answer = depth;
		for (let i = 0; i < n; i++) {
			if (!visited[i] && check(w, words[i])) {
				visited[i] = true;
				dfs(words[i], depth + 1);
				visited[i] = false;
			}
		}
	}

	dfs(begin, 0);
	return answer;
}

console.log(
	solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"])
);
