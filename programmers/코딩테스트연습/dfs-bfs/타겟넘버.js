var answer = 0;

function dfs(numbers, target, cnt, sum) {
	if (cnt >= numbers.length) {
		if (sum == target) answer++;
		return;
	}

	dfs(numbers, target, cnt + 1, sum + numbers[cnt]);
	dfs(numbers, target, cnt + 1, sum - numbers[cnt]);
}

function solution(numbers, target) {
	dfs(numbers, target, 0, 0);
	return answer;
}

console.log(solution([1, 1, 1, 1, 1], 3));
