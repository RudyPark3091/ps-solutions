#include <iostream>
#include <queue>
using namespace std;

int n, m;
int graph[100][100];
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
queue<pair<int, int>> q;

void input() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			graph[i][j] = s[j] - '0';
		}
	}
}

void solve(int dx, int dy) {
	q.push({dx, dy});
	int pf, ps, nx, ny;
	
	while (!q.empty()) {
		pf = q.front().first;
		ps = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = pf + moves[i][0];
			ny = ps + moves[i][1];
			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
			if (bdry && graph[nx][ny] == 1) {
				q.push({nx, ny});
				graph[nx][ny] = graph[pf][ps] + 1;
			}
		}
	}

	return;
}

int main() {
	input();
	solve(0, 0);

	cout << graph[n-1][m-1] << '\n';
	return 0;
}
