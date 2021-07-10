#include <iostream>
#define INF 1e9
using namespace std;

int n, s;
int arr[100001];

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solve() {
	int l = 0;
	int r = 0;
	int sum = arr[0];
	int ans = INF;

	while (l <= r && r < n) {
		if (sum >= s) {
			ans = min(r - l + 1, ans);
			sum -= arr[l];
			l++;
		} else if (sum < s) {
			r++;
			sum += arr[r];
		}
	}
	if (ans == INF) ans = 0;
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
