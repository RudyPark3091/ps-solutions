#include <iostream>
using namespace std;

int main() {
	int p, x, y;
	bool board[2][3][3];
	bool finish = false;
	fill(&board[0][0][0], &board[1][2][3], false);

	cin >> p;
	for (int i = 0; i < 9; i++) {
		bool win = false;
		cin >> x >> y;
		board[p - 1][x - 1][y - 1] = true;

		for (int i = 0; i < 3; i++) {
			if (board[p - 1][i][0] && board[p - 1][i][1] && board[p - 1][i][2])
				win = true;
			if (board[p - 1][0][i] && board[p - 1][1][i] && board[p - 1][2][i])
				win = true;
		}
		if (board[p - 1][0][0] && board[p - 1][1][1] && board[p - 1][2][2])
			win = true;
		if (board[p - 1][2][0] && board[p - 1][1][1] && board[p - 1][0][2])
			win = true;

		if (win && !finish) {
			cout << p << '\n';
			finish = true;
		}
		else if (!finish && i == 8) cout << 0 << '\n';
		p = (p % 2) + 1;
	}

	return 0;
}
