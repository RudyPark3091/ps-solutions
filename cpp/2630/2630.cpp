#include <iostream>
using namespace std;

int n, zeros = 0, ones = 0;
int arr[128][128];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      arr[i][j] == 0 ? zeros++ : ones++;
    }
  }
}

void solve(int size, int dx, int dy) {
  if (size == 1)
    return;

  int nx = dx + size / 2;
  int ny = dy + size / 2;

  bool flag = true;
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { flag = false; }
    }
  }
  if (flag) {
    arr[dx][dy] == 0 ?
      zeros -= size * size - 1 :
      ones -= size * size - 1 ;
    return;
  }

  solve(size / 2, dx, dy);
  solve(size / 2, nx, dy);
  solve(size / 2, dx, ny);
  solve(size / 2, nx, ny);
}

int main() {
  input();
  solve(n, 0, 0);

  cout << zeros << '\n' << ones << '\n';
  return 0;
}

