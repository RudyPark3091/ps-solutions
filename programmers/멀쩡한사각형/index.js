const assert = require("assert");

function gcd(x, y) {
    return y > 0 ? gcd(y, x % y) : x;
}

function solution(w, h) {
    const g = gcd(w, h);
    const x = w / g;
    const y = h / g;
    const dx = y + x - 1;
    return w * h - dx * g;
}

assert.equal(solution(8, 12), 80);
