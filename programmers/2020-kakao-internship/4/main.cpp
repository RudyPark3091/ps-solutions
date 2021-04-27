/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> iii;

int n;
int moves[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int solution(vector<vector<int>> board) {
	n = board.size();

	queue<iii> q;
	q.push({0, 0, -1, 0});
	board[0][0] = 1;
	int answer = 2147483647;

	while (!q.empty()) {
		iii now = q.front();
		q.pop();

		int x = get<0>(now);
		int y = get<1>(now);
		int d = get<2>(now);
		int c = get<3>(now);

		if (x == n - 1 && y == n - 1) {
			if (answer > c) answer = c;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + moves[i][0];
			int ny = y + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < n;
			if (!bdry) continue;

			int cost = c;
			if (d == -1 || d == i) cost += 100;
			else if (d != i) cost += 600;

			if (board[nx][ny] == 0 || board[nx][ny] >= cost) {
				q.push({nx, ny, i, cost});
				board[nx][ny] = cost;
			}
		}
	}

	return answer;
}
