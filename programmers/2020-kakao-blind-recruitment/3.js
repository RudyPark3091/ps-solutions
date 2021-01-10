// 3. 자물쇠와 열쇠

function rotate(key) {
	const n = key.length;
	let arr = Array.from(Array(n), () => Array(n).fill(0));
	for (let i = n - 1; i >= 0; i--) {
		for (let j = 0; j < n; j++) {
			arr[j][n - i - 1] = key[i][j];
		}
	}
	return arr;
}

function setLock(lock) {
	const m = lock.length;
	let arr = Array.from(Array(3 * m), () => Array(3 * m).fill(0));
	for (let i = m; i < 2 * m; i++) {
		for (let j = m; j < 2 * m; j++) {
			arr[i][j] = lock[i - m][j - m];
		}
	}
	return arr;
}

function validate(key, _lock, n, m, dx, dy) {
	let arr = Array.from(Array(3 * m), () => Array(3 * m).fill(0));
	for (let i = 0; i < n; i++) {
		for (let j = 0; j < n; j++) {
			arr[i + dx][j + dy] = key[i][j];
		}
	}
	for (let i = m; i < 2 * m; i++) {
		for (let j = m; j < 2 * m; j++) {
			if (_lock[i][j] == 0 && arr[i][j] == 0) return false;
			if (_lock[i][j] == 1 && arr[i][j] == 1) return false;
		}
	}
	return true;
}

function solution(key, lock) {
	const n = key.length;
	const m = lock.length;

	let _lock = setLock(lock);

	const offset = m - n + 1;
	for (let r = 0; r < 4; r++) {
		for (let i = 0; i < m + n; i++) {
			for (let j = 0; j < m + n; j++) {
				if (validate(key, _lock, n, m, offset + i, offset + j)) {
					return true;
				}
			}
		}
		key = rotate(key);
	}
	return false;
}
