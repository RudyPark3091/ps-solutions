#include <iostream>
#define MAX 1500000
#define MOD 1000000
using namespace std;

long long n;
int arr[MAX] = { 0, 1 };

int main() {
  cin >> n;
  for (int i = 2; i <= n % MAX; i++) { arr[i] = (arr[i-1] + arr[i-2]) % MOD; }
  cout << arr[n % MAX] << '\n';

  return 0;
}
