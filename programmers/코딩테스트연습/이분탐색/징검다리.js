function solution(distance, rocks, n) {
	rocks.sort((a, b) => a - b);

	let ans = 0;
	let left = 1;
	let right = distance;
	let mid = 0;

	while (left <= right) {
		mid = Math.floor((left + right) / 2);
		let cnt = 0;
		let prev = 0;

		rocks.forEach((num) => {
			if (num - prev < mid) cnt++;
			else prev = num;
		});
		cnt += (distance - prev) < mid ? 1 : 0;

		if (cnt <= n) {
			left = mid + 1;
			ans = Math.max(ans, mid);
		} else {
			right = mid - 1;
		}
	}
	return ans;
}
