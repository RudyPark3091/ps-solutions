#include <iostream>
using namespace std;

int n, m;
int arr[8];

void foo(int idx, int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
    return;
  }

  for (int i = idx; i < n; i++) {
    arr[cnt] = i + 1;
    foo(i , cnt + 1);
  }
}

int main(void) {
  cin >> n >> m;

  foo(0, 0);
  return 0;
}