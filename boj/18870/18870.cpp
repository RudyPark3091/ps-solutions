#include <iostream>
#include <vector>
using namespace std;

int n, x;
vector<pair<int, int>> v;
int ans[1000001] = {0, };

void solve() {
	int cnt = 0;
	sort(v.begin(), v.end());
	ans[v[0].second] = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {
			ans[v[i].second] = cnt;
		} else {
			ans[v[i].second] = ++cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back({x, i});
	}
	solve();
	return 0;
}
