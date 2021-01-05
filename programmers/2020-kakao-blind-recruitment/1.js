// 1. 문자열 압축

function solution(s) {
	let answer = s.length;

	for (let i = 1; i < s.length / 2 + 1; i++) {
		let len = s.length;
		let token = s.substr(0, i);
		let flag = false;
		let sameToken = 0;

		for (let j = i; j < s.length + i; j += i) {
			if (s.substr(j, i) === token) {
				sameToken += 1;
				flag = true;
			} else {
				token = s.substr(j, i);
				if (flag) {
					len =
						len - sameToken * i + (sameToken + 1).toString().length;
					sameToken = 0;
					flag = false;
				}
			}
		}

		if (len < answer) {
			answer = len;
		}
	}

	return answer;
}
