## Problem

[acmicpc.net/problem/14502]

## Example

input ->  
7 7  
2 0 0 0 1 1 0  
0 0 1 0 1 2 0  
0 1 1 0 1 0 0  
0 1 0 0 0 0 0  
0 0 0 0 0 1 1  
0 1 0 0 0 0 0  
0 1 0 0 0 0 0  

ouput ->  
27

input ->  
4 6  
0 0 0 0 0 0  
1 0 0 0 0 2  
1 1 1 0 0 2  
0 0 0 0 0 2  

output ->  
9

input ->  
8 8  
2 0 0 0 0 0 0 2  
2 0 0 0 0 0 0 2  
2 0 0 0 0 0 0 2  
2 0 0 0 0 0 0 2  
2 0 0 0 0 0 0 2  
0 0 0 0 0 0 0 0  
0 0 0 0 0 0 0 0  
0 0 0 0 0 0 0 0  

output ->  
3

## Logic

이 문제는 제한시간이 2초이고, n과 m의 범위가 최대 8로 충분히 작은 수로 주어진다.  
따라서 모든 경우의 수를 다 따져보는 브루트 포스 알고리즘을 사용한다.  
3개의 벽을 세우기 위해 반복문을 구성한다.  
각 벽마다 연구소의 모든 지점을 탐색해야 하므로 `3 * n * m - (..)`회의 iteration을 가진다.  
이때 겹치는 부분이 없어야 하므로, 각 좌표를 다르게 두기 위해 `0 ~ n * m` 까지 loop을 돌리고,  
해당 index를 m으로 나눈 몫을 x좌표, 나머지를 y좌표로 하도록 벽을 설치한다.  
입력을 받을 때 2와 1의 좌표의 기억해 둔다.  
기억해둔 2의 좌표 각 지점에서 dfs/bfs탐색을 한다.  
탐색 시 바이러스가 퍼질 수 있는 좌표에 2를 할당해준다.  
탐색 종료 후 바이러스가 퍼지지 못하는 지점의 넓이를 평가한다.  
평가 후 기억해둔 2의 좌표와 1의 좌표를 기반으로 다시 그래프를 초기화한다.  
위 과정을 반복하며 '안전지대'의 최대 넓이를 구한다.  
  
## Source Code
``` cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[8][8];
bool visited[8][8] = { false };
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<pair<int, int>> twos;
vector<pair<int, int>> ones;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) twos.push_back({i, j});
			if (graph[i][j] == 1) ones.push_back({i, j});
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({x, y});

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = _x + moves[i][0];
			int ny = _y + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
			if (!bdry) continue;
			if (!visited[nx][ny] && graph[nx][ny] == 0) {
				q.push({nx, ny});
				visited[nx][ny] = true;
				graph[nx][ny] = 2;
			}
		}
	}
}

int evaluate() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				res++;
			}
		}
	}
	return res;
}

int check(
	int x1,
	int y1,
	int x2,
	int y2,
	int x3,
	int y3
) {
	int res = 0;
	graph[x1][y1] = 1;
	graph[x2][y2] = 1;
	graph[x3][y3] = 1;
	for (auto two : twos) {
		int _x = two.first;
		int _y = two.second;
		bfs(two.first, two.second);
	}

	res = evaluate();
	fill(&graph[0][0], &graph[7][8], 0);
	fill(&visited[0][0], &visited[7][8], false);
	for (auto two : twos) graph[two.first][two.second] = 2;
	for (auto one : ones) graph[one.first][one.second] = 1;
		
	return res;
}

int solve() {
	int ret = 0;

	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m; j++) {
			for (int k = j + 1; k < n * m; k++) {
				int x1 = i / m;
				int y1 = i % m;
				int x2 = j / m;
				int y2 = j % m;
				int x3 = k / m;
				int y3 = k % m;

				bool yes = graph[x1][y1] == 0 && graph[x2][y2] == 0 &&
					graph[x3][y3] == 0;
				if (yes) {
					int res = check(x1, y1, x2, y2, x3, y3);
					if (res > ret) ret = res;
				}
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	input();
	cout << solve() << '\n';
	return 0;
}
```
  
[acmicpc.net/problem/14502]: https://acmicpc.net/problem/14502
