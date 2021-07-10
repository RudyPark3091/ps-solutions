#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool graph[26][26];
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string line;
		cin >> line;
		for (int j = 1; j <= n; j++) {
			graph[i][j] = line[j-1] - '0';
		}
	}
}

int solve(int dx, int dy) {
	int ret = 0;
	bool bdry = 0 < dx && dx <= n && 0 < dy && dy <= n;
	if (!bdry) return 0;

	if (graph[dx][dy]) {
		ret++;
		graph[dx][dy] = false;
		for (int i = 0; i < 4; i++) {
			ret += solve(dx + moves[i][0], dy + moves[i][1]);
		}
		return ret;
	}

	return 0;
}

int main() {
	int cnt = 0;
	int lst[255 / 2] = { 0 };
	input();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			lst[cnt] = solve(i, j);
			if (lst[cnt]) {
				cnt++;
			}
		}
	}

	sort(lst, lst + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << lst[i] << '\n';
	}

	return 0;
}
