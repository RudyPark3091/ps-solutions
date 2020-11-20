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
