#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n = 19;
	int arr[20][20] = { 0 };
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			bool yes = false;
			if (j <= 15) {
				yes = arr[i][j] == arr[i][j + 1] &&
					arr[i][j] == arr[i][j + 2] &&
					arr[i][j] == arr[i][j + 3] &&
					arr[i][j] == arr[i][j + 4] &&
					arr[i][j] != arr[i][j + 5];
				if (j > 0)
					yes = yes && arr[i][j] != arr[i][j - 1];
			}

			if (i <= 15) {
				yes = yes || arr[i][j] == arr[i + 1][j] &&
					arr[i][j] == arr[i + 2][j] &&
					arr[i][j] == arr[i + 3][j] &&
					arr[i][j] == arr[i + 4][j] &&
					arr[i][j] != arr[i + 5][j];
				if (i > 0)
					yes = yes && arr[i][j] != arr[i - 1][j];
			}
			
			if (i <= 15 && i <= 15) {
				yes = yes || arr[i][j] == arr[i + 1][j + 1] &&
					arr[i][j] == arr[i + 2][j + 2] &&
					arr[i][j] == arr[i + 3][j + 3] &&
					arr[i][j] == arr[i + 4][j + 4] &&
					arr[i][j] != arr[i + 5][j + 5];
				if (i > 0 && j > 0)
					yes = yes && arr[i][j] != arr[i - 1][j - 1];
			}

			if (yes) {
				flag = false;
				cout << arr[i][j] << '\n';
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			if (i < 4 && j < 4) continue;
			bool yes = arr[i][j] == arr[i + 1][j - 1] &&
				arr[i][j] == arr[i + 2][j - 2] &&
				arr[i][j] == arr[i + 3][j - 3] &&
				arr[i][j] == arr[i + 4][j - 4] &&
				arr[i][j] != arr[i - 1][j + 1];

			if (i < 15 && j > 4)
				yes = yes && arr[i][j] != arr[i + 5][j - 5];
			if (yes) {
				flag = false;
				cout << arr[i][j] << '\n';
				cout << i + 5 << ' ' << j - 3 << '\n';
			}
		}
	}

	if (flag) cout << 0 << '\n';
	return 0;
}
