/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> min_tree;
vector<int> max_tree;

void setup() {
	cin >> n >> m;
	arr.reserve(n);
	min_tree.reserve(4 * n);
	max_tree.reserve(4 * n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void init(int idx, int left, int right) {
	if (left == right) {
		min_tree[idx] = max_tree[idx] = arr[left];
		return;
	}

	int mid = (left + right) / 2;
	init(idx * 2, left, mid);
	init(idx * 2 + 1, mid + 1, right);

	min_tree[idx] = min(min_tree[idx * 2], min_tree[idx * 2 + 1]);
	max_tree[idx] = max(max_tree[idx * 2], max_tree[idx * 2 + 1]);
}

pair<int, int> query(int idx, int a, int b, int left, int right) {
	if (b < left || right < a) {
		return {2147483647, 0};
	}

	if (a <= left && right <= b) {
		return {
			min_tree[idx],
			max_tree[idx]
		};
	}

	int mid = (left + right) / 2;
	pair<int, int> l = query(idx * 2, a, b, left, mid);
	pair<int, int> r = query(idx * 2 + 1, a, b, mid + 1, right);

	int _min = min(l.first, r.first);
	int _max = max(l.second, r.second);

	return {_min, _max};
}

void solve() {
	int x, y;
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		pair<int, int> res = query(1, x - 1, y - 1, 0, n - 1);
		cout << res.first << ' ' << res.second << '\n';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
