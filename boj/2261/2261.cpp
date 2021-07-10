#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2147000000
using namespace std;

typedef pair<int, int> coord;

int N;
long long dist;
vector<coord> v;

int get_distance(coord &a, coord &b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool comp(coord &a, coord &b) {
  return a.second < b.second;
}

int solve(int a, int n) {
  if (n == 2) return get_distance(v[a], v[a+1]);
  else if (n == 3)
    return min({
          get_distance(v[a], v[a+1]),
          get_distance(v[a+1], v[a+2]),
          get_distance(v[a+2], v[a])
        });

  int l = (v[a + n/2 - 1].first + v[a + n/2].first) / 2;
  int minimum = min(solve(a, n/2), solve(a + n/2, n - n/2));

  vector<coord> v_tmp;
  v_tmp.reserve(n);

  for (int i = 0; i < n; i++) {
    int tmp = l - v[a + i].first;
    if (tmp * tmp < minimum) {
      v_tmp.push_back(v[a + i]);
    }
  }

  sort(v_tmp.begin(), v_tmp.end(), comp);

  int sz = v_tmp.size();
  for (int i = 0; i < sz - 1; i++) {
    for (int j = i + 1; j < sz && (v_tmp[j].second - v_tmp[i].second) * (v_tmp[j].second - v_tmp[i].second) < minimum; j++) {
      minimum = min(minimum, get_distance(v_tmp[i], v_tmp[j]));
    }
  }

  return minimum;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  cout << solve(0, N) << '\n';
  return 0;
}
