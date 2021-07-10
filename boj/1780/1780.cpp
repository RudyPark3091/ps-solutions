#include <iostream>
#define MAX 2187
using namespace std;

int n;
int nums[3];
int arr[MAX][MAX];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      nums[arr[i][j] + 1]++;
    }
  }
}

bool check(int size, int dx, int dy) {
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { return false; }
    }
  }
  return true;
}

void solve(int size, int dx, int dy) {
  if (size == 1) { return; }

  int nx = dx + size / 3;
  int nx2 = dx + 2 * size / 3;
  int ny = dy + size / 3;
  int ny2 = dy + 2 * size / 3;

  if (check(size, dx, dy)) {
    nums[arr[dx][dy] + 1] -= size * size - 1;
    return;
  }

  solve(size / 3, dx, dy);
  solve(size / 3, dx, ny);
  solve(size / 3, dx, ny2);
  solve(size / 3, nx, dy);
  solve(size / 3, nx, ny);
  solve(size / 3, nx, ny2);
  solve(size / 3, nx2, dy);
  solve(size / 3, nx2, ny);
  solve(size / 3, nx2, ny2);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve(n, 0, 0);

  cout << nums[0] << '\n' << nums[1] << '\n'<< nums[2] << '\n';
  return 0;
}
