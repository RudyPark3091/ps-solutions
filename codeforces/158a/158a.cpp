#include <iostream>
using namespace std;

int main() {
  int n, k;
  int man = 0;
  int arr[50];

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++) {
    if (arr[i] >= arr[k - 1] && arr[i] > 0)
      man++;
  }

  cout << man << '\n';

  return 0;
}
