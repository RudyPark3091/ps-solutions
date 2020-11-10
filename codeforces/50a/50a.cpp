#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (m * n % 2 == 0)
    cout << m * n / 2 << '\n';
  else
    cout << (m * n - 1) / 2 << '\n';

  return 0;
}
