/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int n, m, a, b;
bool srch = false;
bool mat[101][101];
bool visited[101];

void setup() {
  int x, y;
  cin >> n >> a >> b >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    mat[x][y] = true;
    mat[y][x] = true;
  }
}

void dfs(int start, int depth) {
  if (start == b) {
    cout << depth << '\n';
    srch = true;
    return;
  }

  for (int i = 0; i <= 101; i++) {
    if (!visited[i] && mat[start][i]) {
      visited[i] = true;
      dfs(i, depth + 1);
    }
  }
}

void solve() {
  visited[a] = true;
  dfs(a, 0);
  if (!srch) cout << -1 << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
