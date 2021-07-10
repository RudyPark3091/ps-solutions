#include <iostream>
#include <queue>
using namespace std;

struct cmp {
  bool operator() (int n1, int n2) {
    if (abs(n1) > abs(n2))
      return true;
    else if (abs(n1) == abs(n2)) {
      if (n1 > n2)
        return true;
      else
        return false;
    }
    return false;
  }
};

int n;
priority_queue<int, vector<int>, cmp> pq;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == 0) {
      if (pq.empty())
        cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else
      pq.push(t);

  }
  return 0;
}
