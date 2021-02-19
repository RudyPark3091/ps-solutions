#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	bool arr1[301][301];
	bool arr2[301][301];
	int res = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool yes = false;
			for (int k = 0; k < n; k++) {
				yes = yes || (arr1[i][k] && arr2[k][j]);
			}
			if (yes) res += 1;
		}
	}

	cout << res << '\n';
	return 0;
}
