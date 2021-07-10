#include <iostream>
#define DIV 1000000007
#define MUL 1000000005
#define MAX 4000001
using namespace std;

int n, k;

long long pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 != 0) {
      res *= x;
      res %= DIV;
    }
    x *= x;
    x %= DIV;
    y /= 2;
  }
  return res;
}

long long solve() {
  long long arr[n+1] = { 1, 1, };
  for (int i = 2; i <= n; i++) {
    arr[i] = (arr[i-1] * i) % DIV;
  }
  long long nFac = arr[n];
  long long kFac = arr[k];
  long long nmkFac = arr[n - k];
  long long rval = pow((kFac * nmkFac) % DIV, MUL);

  return ((nFac % DIV) * (rval % DIV)) % DIV;
}

int main() {
  cin >> n >> k;
  cout << solve() << '\n';
  return 0;
}
