function search(n, times, a, b) {
    let left = a;
    let right = b;
    let ret = 0;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        const res = times
        	.map(t => Math.floor(mid / t))
        	.reduce((acc, cur) => acc + cur);
        if (res >= n) {
            right = mid - 1;
            ret = mid;
        } else left = mid + 1;
    }
    return ret;
}

function solution(n, times) {
    const max = Math.max(...times);

    const left = 0;
    const right = n * max;
    return search(n, times, left, right);
}
