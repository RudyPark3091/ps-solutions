#include <iostream>
using namespace std;

int n, x;
int arr[10] = { 0 };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (cnt == x && arr[j] == 0) {
				arr[j] = i + 1;
				break;
			} else if (arr[j] == 0) {
				cnt += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}
