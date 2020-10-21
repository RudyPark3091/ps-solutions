#include <iostream>
using namespace std;

int n;
int arr[64][64];
string res;

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) { arr[i][j] = s.at(j) - 48; }
  }
}

void solve(int size, int dx, int dy) {
  if (size == 1) {
    res += arr[dx][dy] + 48;
    return;
  }

  int nx = dx + size / 2;
  int ny = dy + size / 2;
  
  bool flag = true;
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { flag = false; }
    }
  }
  if (flag) {
    res += arr[dx][dy] + 48;
    return;
  }

  res += '(';
  solve(size / 2, dx, dy);
  solve(size / 2, dx, ny);
  solve(size / 2, nx, dy);
  solve(size / 2, nx, ny);
  res += ')';
}

int main() {
  input();
  solve(n, 0, 0, 0);

  cout << res << '\n';
  return 0;
}
