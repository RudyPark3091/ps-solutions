#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int a, b;
queue<pair<ll, int> > q;

int solve(int _a, int _b, int depth) {
	q.push(make_pair(_a, depth));

	while (!q.empty()) {
		long long x = q.front().first;
		int d = q.front().second;
		q.pop();
		if (x == _b) return d;
		if (x > _b) continue;

		if (x * 2 <= _b) {
			q.push(make_pair(x * 2, d + 1));
		}
		if (x * 10 + 1 <= _b) {
			q.push(make_pair(x * 10 + 1, d + 1));
		}
	}

	return -1;
}

int main() {
	cin >> a >> b;
	cout << solve(a, b, 1) << '\n';

	return 0;
}
