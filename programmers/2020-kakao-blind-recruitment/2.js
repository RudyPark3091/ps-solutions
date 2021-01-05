// 2. 괄호 변환

function split(p) {
	let l = 0;
	let r = 0;
	let u = "";

	for (let i = 0; i < p.length; i++) {
		if (p[i] === "(") {
			l += 1;
			u += "(";
		} else if (p[i] === ")") {
			r += 1;
			u += ")";
		}
		if (l === r) {
			break;
		}
	}

	const v = p.replace(u, "");
	return [u, v];
}

function check(p) {
	const stack = [];
	for (let i = 0; i < p.length; i++) {
		if (p[i] === "(") {
			stack.push(1);
		} else if (p[i] === ")") {
			stack.pop();
		}
	}
	if (stack.length === 0) return true;
	else return false;
}

function revrse(p) {
	let buf = "";
	for (let i = 0; i < p.length; i++) {
		if (p[i] === "(") {
			buf += ")";
		} else if (p[i] === ")") {
			buf += "(";
		}
	}
	return buf;
}

function solution(p) {
	if (p === "") return "";
	let [u, v] = split(p);
	if (check(u)) {
		v = solution(v);
		return u + v;
	} else {
		let buf = "";
		buf += "(";
		buf += solution(v);
		buf += ")";
		u = u.substring(1, u.length - 1);
		buf += revrse(u);
		return buf;
	}
}
