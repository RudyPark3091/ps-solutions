/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

int n, w, l;
int arr[1001];

void setup() {
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	queue<ii> q;
	int t = 1;
	int on = arr[0];
	int next = 1;
	q.push({arr[0], t + w});

	while (!q.empty() || next < n) {
		if (next < n && on + arr[next] <= l) {
			on += arr[next];
			q.push({arr[next], t + w - 1});
			next += 1;
		}

		if (q.front().second <= t) {
			on -= q.front().first;
			q.pop();
		}
		t += 1;
	}

	cout << t - 1 << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
