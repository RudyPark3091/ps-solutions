#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int arr[100001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
}

void solve() {
	sort(arr, arr + n);
	int left = 0;
	int right = n - 1;
	int ans = 0;

	while (left < right) {
		int val = arr[left] + arr[right];
		if (val == x) {
			ans++;
			left++;
		} else if (val > x) {
			right--;
		} else {
			left++;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
