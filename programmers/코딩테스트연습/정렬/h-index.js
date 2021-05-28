function solution(citations) {
	const loop = (i, arr) =>
		(i >= arr.length || arr[i] <= i) ? i : loop(i + 1, arr);
	return loop(0, citations.sort((a, b) => b - a));
}
