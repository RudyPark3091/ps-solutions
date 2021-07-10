#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n;
ll arr[100001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
}

ll _abs(ll a) {
	return a >= 0 ? a : -1 * a;
}

void solve() {
	ll left = 0;
	ll right = n - 1;
	ll _min = 2100000000;
	ll left_value = arr[0];
	ll right_value = arr[n - 1];

	while (left < right) {
		ll value = arr[left] + arr[right];
		cout << arr[left] << " + " << arr[right] << " = " << value << '\n';
		if (_abs(value) < _min) {
			_min = _abs(value);
			left_value = arr[left];
			right_value = arr[right];
		}
		if (value < 0) {
			left++;
		} else if (value > 0) {
			right--;
		} else {
			break;
		}
	}

	cout << left_value << ' ' << right_value << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
