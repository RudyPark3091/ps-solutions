#include <iostream>
#include <algorithm>
using namespace std;

string str1;
string str2;
int arr[1001][1001];

void input() {
  cin >> str1;
  cin >> str2;
}

void solve() {
  for (int i = 1; i <= str1.length(); i++) {
    for (int j = 1; j <= str2.length(); j++) {
      if (str1.at(i-1) == str2.at(j-1)) {
        arr[j][i] = arr[j-1][i-1] + 1;
      } else {
        arr[j][i] = max(arr[j-1][i], arr[j][i-1]);
      }
    }
  }

  cout << arr[str2.length()][str1.length()] << '\n';
}

int main() {
  input();
  solve();

  return 0;
}
