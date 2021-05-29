function solution(answers) {
    const a = [1, 2, 3, 4, 5];
    const b = [2, 1, 2, 3, 2, 4, 2, 5];
    const c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

    const as = answers.filter((v, i) => v === a[i % a.length]);
    const bs = answers.filter((v, i) => v === b[i % b.length]);
    const cs = answers.filter((v, i) => v === c[i % c.length]);

    const arr = [as, bs, cs].map((v, i) => [i + 1, v.length]);
    const m = Math.max(...arr.map(v => v[1]));
    return arr.filter(v => v[1] === m).map(v => v[0]);
}
