## Problem
[acmicpc.net/problem/1780]   
   
## Example
input ->   
9   
0 0 0 1 1 1 -1 -1 -1   
0 0 0 1 1 1 -1 -1 -1   
0 0 0 1 1 1 -1 -1 -1   
1 1 1 0 0 0 0 0 0   
1 1 1 0 0 0 0 0 0   
1 1 1 0 0 0 0 0 0   
0 1 -1 0 1 -1 0 1 -1   
0 -1 1 0 1 -1 0 1 -1   
0 1 -1 1 0 -1 0 1 -1   
   
output ->   
10   
12   
11   
   
## Logic
이 문제는 [2630번]문제와 거의 동일한 문제다.   
동일한 논리로 문제를 해결했는데, 한 가지 짚고 넘어갈점이 있다.   
2630번은 N의 범위가 128 이하로 충분히 작지만 이 문제는 N의 범위가 2187로, 상당히 크다.   
따라서 입력을 받을때 약간의 시간이 걸린다.   
이 문제는 main함수의 첫 부분에 코드 두 줄을 추가함으로서 해결가능하다.   
`cin.tie(NULL)`, `ios_base::sync_with_stdio(false)`를 추가한다.   
`cin.tie(NULL)`은 cout과 cin를 untie하는 역할을 한다.   
기본적으로 cin과 cout은 tie되어있어 입력을 받기 전에 출력 버퍼를 비워준다.   
`cin.tie(NULL)`을 입력해주면 cin과 cout을 untie해줘 더 빠르게 입력을 받을 수 있게 한다.   
`ios_base::sync_with_stdio(false)`는 c++의 iostream과 c의 stdio의 동기화를 끊어주는 역할을 한다.   
이를 사용하면 c의 buffer와 병행하여 사용할 수 없지만 입출력 속도를 빠르게 해준다.   
이 두 줄의 코드를 사용하지 않아도 시간초과는 나지 않지만, 입력량이 많아지는 경우엔 사용을 고려해야 할 듯 하다.   
   
## Source Code
``` cpp
#include <iostream>
#define MAX 2187
using namespace std;

int n;
int nums[3];
int arr[MAX][MAX];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      nums[arr[i][j] + 1]++;
    }
  }
}

bool check(int size, int dx, int dy) {
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { return false; }
    }
  }
  return true;
}

void solve(int size, int dx, int dy) {
  if (size == 1) { return; }

  int nx = dx + size / 3;
  int nx2 = dx + 2 * size / 3;
  int ny = dy + size / 3;
  int ny2 = dy + 2 * size / 3;

  if (check(size, dx, dy)) {
    nums[arr[dx][dy] + 1] -= size * size - 1;
    return;
  }

  solve(size / 3, dx, dy);
  solve(size / 3, dx, ny);
  solve(size / 3, dx, ny2);
  solve(size / 3, nx, dy);
  solve(size / 3, nx, ny);
  solve(size / 3, nx, ny2);
  solve(size / 3, nx2, dy);
  solve(size / 3, nx2, ny);
  solve(size / 3, nx2, ny2);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve(n, 0, 0);

  cout << nums[0] << '\n' << nums[1] << '\n'<< nums[2] << '\n';
  return 0;
}
```


[acmicpc.net/problem/1780]: acmicpc.net/problem/1780
[2630번]: acmicpc.net/problem/2630
