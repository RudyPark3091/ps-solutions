#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, t;
  priority_queue<int, vector<int>, greater<int>> minq;
  priority_queue<int> maxq;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t;

    if (minq.size() == maxq.size()) {
      maxq.push(t);
    } else {
      minq.push(t);
    }

    if (!maxq.empty() && !minq.empty()) {
      if (maxq.top() > minq.top()) {
        // swap
        int maxtp = maxq.top();
        int mintp = minq.top();

        maxq.pop(); minq.pop();
        maxq.push(mintp);
        minq.push(maxtp);
      }
    }
    cout << maxq.top() << '\n';
  }
  return 0;
}
