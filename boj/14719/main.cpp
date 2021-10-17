#include <iostream>
#include <algorithm>
using namespace std;

int w, h;
int v[501];

void input() {
  cin >> h >> w;
  for (int i = 0; i < w; i++) {
    cin >> v[i];
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  input();
  int ans = 0;
  for (int i = 1; i < w - 1; i++) {
    int left = *max_element(v, v + i);
    int right = *max_element(v + i, v + w);
    int x = min(left, right) - v[i];
    ans += max(x, 0);
  }

  cout << ans << '\n';
  return 0;
}
