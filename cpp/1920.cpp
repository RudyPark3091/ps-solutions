#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int narr[100000];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> narr[i];
  }
}

int solve(int a, int b, int target) {
  int mid = 0;
  while (a <= b) {
    mid = (b + a) / 2;
    if (target < narr[mid]) {
      b = mid - 1;
    } else if (target > narr[mid]) {
      a = mid + 1;
    } else if (target == narr[mid]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int t;

  input();
  sort(narr, narr+n);

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    cout << solve(0, n, t) << '\n';
  }
  return 0;
}
