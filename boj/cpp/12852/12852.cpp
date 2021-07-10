#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000001
using namespace std;

int n;
int costs[MAX];
int pre[MAX];

void solve(int n) {
	costs[1] = 0;
	pre[1] = 0;

	for (int i = 2; i <= n; i++) {
		costs[i] = costs[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && costs[i] > costs[i / 2]) {
			costs[i] = costs[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && costs[i] > costs[i / 3]) {
			costs[i] = costs[i / 3] + 1;
			pre[i] = i / 3;
		}
	}

	cout << costs[n] << '\n' << n << ' ';
	while (pre[n] != 0) {
		cout << pre[n] << ' ';
		n = pre[n];
	}
	cout << '\n';
}

int main() {
	cin >> n;
	solve(n);
	return 0;
}
