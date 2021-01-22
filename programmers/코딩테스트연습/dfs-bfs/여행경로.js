function solution(tickets) {
	let answer = [];

	function dfs(tickets, ap, ans = ["ICN"]) {
		if (tickets.length === 0) answer.push(ans);
		else {
			for (let i = 0; i < tickets.length; i++) {
				let from = tickets[i][0];
				let to = tickets[i][1];
				if (from === ap) {
					let rest = Array.from(tickets);
					rest.splice(i, 1);
					dfs(rest, to, ans.concat(to));
				}
			}
		}
	}

	dfs(tickets, "ICN");
	return answer.sort()[0];
}

console.log(
	solution([
		["ICN", "SFO"],
		["ICN", "ATL"],
		["SFO", "ATL"],
		["ATL", "ICN"],
		["ATL", "SFO"],
	])
);
