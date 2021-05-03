/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> iii;

int n;
int graph[26][26][4];
int moves[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int solution(vector<vector<int>> board) {
	n = board.size();

	queue<iii> q;
	q.push({0, 0, -1});
	board[0][0] = 1;
	int answer = 2147483647;
	fill(&graph[0][0][0], &graph[25][25][4], 2147483647);

	while (!q.empty()) {
		iii now = q.front();
		q.pop();

		int x = get<0>(now);
		int y = get<1>(now);
		int d = get<2>(now);

		for (int i = 0; i < 4; i++) {
			int nx = x + moves[i][0];
			int ny = y + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < n;
			if (!bdry || board[nx][ny] == 1) continue;

			int cost = 0;
			if (d == -1 || d == i) cost = 100;
			else cost = 600;

			if (graph[nx][ny][i] > graph[x][y][d] + cost) {
				graph[nx][ny][i] = graph[x][y][d] + cost;
				q.push({nx, ny, i});
			}
		}
	}

	for (int i = 0; i  < 4; i++) {
		answer = min(answer, graph[n - 1][n - 1][i]);
	}

	return answer;
}
