#include <iostream>
#include <queue>
using namespace std;

int t, n, m;

int main() {
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int a, idx, val, cnt = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    cin >> n >> m;
    for (int j = 0; j < n; j++) {
      cin >> a;
      q.push({j, a});
      pq.push(a);
    }

    while (!q.empty()) {
      idx = q.front().first;
      val = q.front().second;
      q.pop();

      if (pq.top() == val) {
        pq.pop();
        cnt++;
        if (idx == m) {
          cout << cnt << '\n';
          break;
        }
      } else {
        q.push({idx, val});
      }
    }

  }

  return 0;
}

