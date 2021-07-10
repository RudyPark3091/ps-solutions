#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> arr;
vector<ll> tree;

ll init(int node_index, int left, int right) {
	if (left == right) {
		return tree[node_index] = arr[left];
	}

	int mid = (left + right) / 2;
	return tree[node_index] = 
		init(node_index * 2, left, mid) +
		init(node_index * 2 + 1, mid + 1, right);
}

void update(int node_index, int index, int left, int right, ll diff) {
	if (!(left <= index && index <= right)) {
		return;
	}

	tree[node_index] += diff;

	if (left != right) {
		int mid = (left + right) / 2;
		update(node_index * 2, index, left, mid, diff);
		update(node_index * 2 + 1, index, mid + 1, right, diff);
	}
}

ll query(int node_index, int a, int b, int left, int right) {
	if (b < left || right < a) {
		return 0;
	}

	if (a <= left && right <= b) {
		return tree[node_index];
	}

	int mid = (left + right) / 2;
	return query(node_index * 2, a, b, left, mid) +
		query(node_index * 2 + 1, a, b, mid + 1, right);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	arr.reserve(n);
	tree.reserve(4 * n);

	ll a, b, c;
	int root = 1;
	int left = 0;
	int right = n - 1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(root, left, right);
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			update(root, b - 1, left, right, c - arr[b - 1]);
			arr[b - 1] = c;
		} else {
			cout << query(root, b - 1, c - 1, left, right) << '\n';
		}
	}

	return 0;
}
