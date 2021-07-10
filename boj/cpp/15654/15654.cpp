#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int res[8];
bool visited[8] = { false };

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res[cnt] = arr[i];
			solve(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	solve(0);
	return 0;
}
