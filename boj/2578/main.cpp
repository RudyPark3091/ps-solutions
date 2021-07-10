/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int x;

	bool check[5][5];
	pair<int, int> row[25];
	int call[25];
	fill(&check[0][0], &check[4][5], false);

	for (int i = 0; i < 25; i++) {
		cin >> x;
		x--;
		row[x] = {i / 5, i % 5};
	}
	for (int i = 0; i < 25; i++) cin >> call[i];

	for (int idx = 0; idx < 25; idx++) {
		pair<int, int> coord = row[call[idx] - 1];
		check[coord.first][coord.second] = true;

		int bingos = 0;

		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (check[i][j]) cnt++;
			}
			if (cnt == 5) bingos++;
		}

		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (check[j][i]) cnt++;
			}
			if (cnt == 5) bingos++;
		}

		for (int i = 0; i < 5; i++) {
			if (!check[i][i]) break;
			if (i == 4) bingos++;
		}

		for (int i = 0; i < 5; i++) {
			if (!check[4 - i][i]) break;
			if (i == 4) bingos++;
		}

		if (bingos >= 3) {
			cout << idx + 1 << '\n';
			return 0;
		}
	}

	return 0;
}
