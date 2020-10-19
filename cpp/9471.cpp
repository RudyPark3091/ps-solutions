#include <iostream>
using namespace std;

int n, m, v1, v2;

int solve(int num) {
  int cnt = 0;
  v1 = 0;
  v2 = 1;

  while (true) {
    if (v1 == 0 && v2 == 1 && cnt != 0) { return cnt; }

    int tmp = v1;
    v1 = v2;
    v2 = (tmp + v1) % m;
    cnt++;
  }
}

int main() {
  int p;
  cin >> p;
  
  for (int ts = 0; ts < p; ts++) {
    cin >> n >> m;
    cout << n << ' ' << solve(m) << '\n';
  }

  return 0;
}
