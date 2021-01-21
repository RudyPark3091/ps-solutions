## Problem
[acmicpc.net/problem/1707]  
  
## Example
input ->  
2  
3 2  
1 3  
2 3  
4 4  
1 2  
2 3  
3 4  
4 2  
  
output ->  
YES  
NO  
  
## Logic
정점의 집합을 둘로 분할하여 각 집합에 속한 정점끼리 인접하지 않는 그래프를 이분 그래프라고 한다.  
처음 문제를 해석할때엔 두 별개의 그래프가 간선 하나로만 연결되어 있는 형태의 그래프를 의미하는 줄 알았다.  
[위키백과]에서 이분 그래프의 예시를 볼 수 있다.  
이분 그래프는 dfs/bfs를 이용하여 판별할 수 있다.  
그래프의 꼭짓점들을 탐색하는데, 각 꼭짓점들을 이웃 꼭짓점과 다른 '색'으로 칠한다.  
이때 같은 색깔의 꼭짓점이 서로 연결되어 있다면 이분 그래프가 아니라고 할 수 있다.  
이를 구현한 코드는 다음과 같다.  
  
## Source Code
``` cpp
#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
int a, b;
vector<int> graph[20001];
int visited[20001];

void input() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int x, int color) {
	visited[x] = color;
	for (int i = 0; i < graph[x].size(); i++) {
		int _next = graph[x][i];
		if (!visited[_next]) {
			dfs(_next, 3 - color);
		}
	}
}

bool yes() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int _next = graph[i][j];
			if (visited[_next] == visited[i]) return false;
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> k;
	for (int i = 0; i < k; i++) {
		if (i != 0) {
			for (int i = 1; i <= v; i++) graph[i].clear();
			fill(visited, visited + v + 1, 0);
		}
		input();
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) dfs(j, 1);
		}
		if (yes()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
```

## Review
fill 함수 사용시 주의할 점:  
두번째 인자에는 마지막 인덱스 + 1 주소를 전달해야 함  
이걸 깜빡해서 디버깅까지 해야했다.  
  

[acmicpc.net/problem/1707]: https://acmicpc.net/problem/1707
[위키백과]: https://ko.wikipedia.org/wiki/이분_그래프
