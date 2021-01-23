#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, now = -1, res = 0;
	int arr[1001] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (now == -1 && arr[i] == 0) {
			now = 0;
			res += 1;
		} if (now == 0 && arr[i] == 1) {
			now = 1;
			res += 1;
		} else if (now == 1 && arr[i] == 2) {
			now = 2;
			res += 1;
		} else if (now == 2 && arr[i] == 0) {
			now = 0;
			res += 1;
		}
	}

	cout << res << '\n';
	return 0;
}
