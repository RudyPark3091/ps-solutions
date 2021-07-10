## Problem
[acmicpc.net/prolem/1520]  
  
## Example
input -> 
4 5  
50 45 37 32 30  
35 50 40 20 25  
30 30 25 17 28  
27 24 22 15 10  
  
ouput ->  
3  
  
## Logic
깊이우선탐색(DFS)로 해결이 가능한 문제이다.  
시작점으로부터 상하좌우에 위치한 가중치값이 작을 때만 이동이 가능하고, 조건에 따른 이동을 계속했을 때 목표지점에 이르면 true 값을 반환한다.  
문제에서 모든 지점의 높이는 자연수임을 명시했으므로 좌표상에 방문한 지점과 방문하지 않은 지점을 구분하기 위해 dp배열의 값을 모두 -1으로 초기화한다.  
현재 방문한 지점이 이전에 방문하지 않은 지점이라면 상,하,좌,우에 위치한 지점을 검사한다.  
이를 재귀적으로 반복하여 방문한 지점이 목표 지점이 된다면 1을 반환한다.  
이때 다음으로 방문하는 지점의 높이값이 현재 지점보다 작다면 값을 갱신해준다.  
현재 방문한 지점이 이전에 방문한 지점이라면 해당하는 위치의 dp배열 값을 반환한다.  
이때 반환하는 값이 0이라면 이전까지 이 지점을 통해 목표지점으로 도달하는 경로를 발견하지 못했음을 의미한다.  
반환하는 값이 0이 아니라면 이전까지 이 지점을 통해 발견한 경로의 개수가 해당 값임을 의미한다.  
최종적으로 재귀가 끝나면 반환하는 값이 시작점에서 목표 지점까지 조건을 만족하며 진행하는 경로의 개수이다.  
  
## Source Code
``` cpp
#include <iostream>
using namespace std;

int n, m;
int arr[501][501];
int dp[501][501];
int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input() {
  cin >> n >>m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }
}

// dfs
int solve(int dx, int dy) {
  if (dx == n && dy == m)
    return 1;

  if (dp[dx][dy] == -1) {
    dp[dx][dy] = 0;

    for (int i = 0; i < 4; i++) {
      int nx = dx + moves[i][0];
      int ny = dy + moves[i][1];

      if (nx <= n && nx > 0 && ny <= m && ny > 0) {
        if (arr[dx][dy] > arr[nx][ny]) {
          dp[dx][dy] += solve(nx, ny);
        }
      }
    }
  }

  return dp[dx][dy];
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();

  cout << solve(1, 1) << '\n';
  return 0;
}
```
  
[acmicpc.net/prolem/1520]: https://acmicpc.net/problem/1520
