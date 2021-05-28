function solution(numbers) {
	const ans = numbers
		.map(n => n.toString())
		.sort((a, b) => +(b + a) - +(a + b))
		.join("");
	return +ans === 0 ? "0" : ans;
}
