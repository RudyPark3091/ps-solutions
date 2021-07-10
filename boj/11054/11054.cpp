#include <iostream>
using namespace std;

int n;
int arr[1001] = { 0, };
int dp_asc[1001] = { 0, };
int dp_desc[1001] = { 0, };

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) { cin >> arr[i]; }
}

void get_asc() {
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        if (dp_asc[j] > cnt) { cnt = dp_asc[j]; }
      }
    } 
    dp_asc[i] = cnt + 1;
  }
}

void get_desc() {
  for (int i = n; i >= 1; i--) {
    int cnt = 0;
    for (int j = n; j >= i; j--) {
      if (arr[i] > arr[j]) {
        if (dp_desc[j] > cnt) { cnt = dp_desc[j]; }
      }
    }
    dp_desc[i] = cnt + 1;
  }
}

void solve() {
  int max = 0;
  for (int i = 1; i <= n; i++) {
    if (max < (dp_asc[i] + dp_desc[i] - 1)) { max = dp_asc[i] + dp_desc[i] - 1; } 
  }
  cout << max << '\n';
}

int main() {
  input();
  get_asc();
  get_desc();
  solve();

  return 0;
}
