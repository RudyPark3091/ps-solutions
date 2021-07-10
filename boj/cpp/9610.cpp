#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, x, y;
	int arr[5] = { 0 };
	cin >> n;
	while (n--) {
		cin >> x >> y;
		if (x > 0) {
			if (y > 0) arr[0] += 1;
			else if (y < 0) arr[3] += 1;
			else arr[4] += 1;
		} else if (x < 0) {
			if (y > 0) arr[1] += 1;
			else if (y < 0) arr[2] += 1;
			else arr[4] += 1;
		} else {
			arr[4] += 1;
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << 'Q' << i + 1 << ": " << arr[i] << '\n';
	}
	cout << "AXIS: " << arr[4] << '\n';

	return 0;
}
