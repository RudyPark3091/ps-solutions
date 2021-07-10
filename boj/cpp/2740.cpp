#include <iostream>
using namespace std;

int n, m, k;
int mat1[101][101];
int mat2[101][101];
int res[101][101];

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { cin >> mat1[i][j]; }
  }
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) { cin >> mat2[i][j]; }
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int tmp = 0;
      for (int ii = 0; ii < m; ii++) {
        tmp += mat1[i][ii] * mat2[ii][j];
      }
      res[i][j] = tmp;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) { cout << res[i][j] << ' '; }
    cout << '\n';
  }

  return 0;
}
