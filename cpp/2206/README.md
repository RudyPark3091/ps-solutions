## Problem
[acmicpc.net/problem/2206]  
  
## Example
input ->  
6 4  
0100  
1110  
1000  
0000  
0111  
0000  
  
output ->  
15  
  
## Logic
주어진 지도에서 한 번만 벽을 부수고 목표지점까지 이동하는 최단 경로를 구하는 문제이다.  
bfs를 사용해 문제를 해결한다.  
이때 벽을 부쉈을때/ 안부쉈을때를 구분하기 위해 주어진 지도 x 2에 대응하는 3차원 배열을 사용한다.  
이때 다음 노드를 탐색하는 조건은  
경계 안에 있는지  
다음 노드가 벽이 아니고 방문하지 않았는지  
다음 노드가 벽이라면 벽을 뚫을 기회가 남았는지  
를 확인한 뒤 큐에 다음 노드를 넣고 이동한다  
만약 큐에서 꺼낸 노드가 목표지점이라면 해당하는 배열의 원소를 return한다.  
  
## Source Code
``` cpp
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> coord;

int n, m;
bool wall[1000][1000];
int visited[1000][1000][2];
queue<coord> q;
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input() {
	string s;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			wall[i][j] = s[j] - '0';
		}
	}
}

int solve(int x, int y, int destx, int desty) {
	visited[x][y][0] = 1;
	q.push({x, y, 0});

	while (!q.empty()) {
		int dx = get<0>(q.front());
		int dy = get<1>(q.front());
		int broken = get<2>(q.front());
		q.pop();

		if (dx == destx && dy == desty) {
			return visited[dx][dy][broken];
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx + moves[i][0];
			int ny = dy + moves[i][1];

			bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;
			if (!bdry) continue;
			// 벽이 아니면 방문여부확인 후 탐색
			if (!wall[nx][ny] && visited[nx][ny][broken] == 0) {
				visited[nx][ny][broken] = visited[dx][dy][broken] + 1;
				q.push({nx, ny, broken});
			}
			// 벽이면 이미 부쉈는지 확인
			// 안 부쉈으면
			if (wall[nx][ny] && !broken) {
				visited[nx][ny][broken+1] = visited[dx][dy][broken] + 1;
				q.push({nx, ny, broken+1});
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cout << solve(0, 0, n-1, m-1) << '\n';

	return 0;
}
```
  

[acmicpc.net/problem/2206]: https://acmicpc.net/problem/2206
