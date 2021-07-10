#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
vector<pair<int, int>> arr;

void input() {
  int a, b;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr.push_back({a, b});
  }
}

bool comp(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  else{
    return a.second < b.second;
  }
}

void solve() {
  sort(arr.begin(), arr.end(), comp);
  int cnt = 1;
  int end = arr[0].second;
  for (int i = 1; i < n; i++) {
    if (end <= arr[i].first) {
      cnt++;
      end = arr[i].second;
    }
  }
  res = cnt;
}

int main() {
  input();
  solve();
  cout << res << '\n';
  return 0;
}
