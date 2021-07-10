#include <iostream>
using namespace std;

int n, m;
int arr[8];

void foo(int cnt)
{
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++)
  {
    arr[cnt] = i + 1;
    foo(cnt + 1);
  }
}

int main(void)
{
  cin >> n >> m;
  foo(0);
  return 0;
}