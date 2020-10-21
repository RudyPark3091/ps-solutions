## Problem
[acmicpc.net/problem/2630]   
   
# Example
input ->   
8   
1 1 0 0 0 0 1 1   
1 1 0 0 0 0 1 1   
0 0 0 0 1 1 0 0   
0 0 0 0 1 1 0 0   
1 0 0 0 1 1 1 1   
0 1 0 0 1 1 1 1   
0 0 1 1 1 1 1 1   
0 0 1 1 1 1 1 1   
   
output ->   
9   
7   
   
## Logic
이 문제는 프로그래머스에서 주최한 [월간 코드 챌린지 시즌 1]에도 출제된 문제다.   
간단히 재귀를 이용한 분할 정복으로 해결가능하다.   
재귀함수는 f(size, offset, offset)의 형식으로 구성한다.   
만약 해당하는 정사각형이 모두 동일한 값을 가진다면 해당 수 만큼 갯수를 감소시키고,   
그렇지 않다면 그 정사각형을 4등분하는 정사각형들에 대해 재귀함수를 호출한다.   
이때 재귀는 size == 1 이 되는순간 종료하도록 한다.   

## Source Code
``` cpp
#include <iostream>
using namespace std;

int n, zeros = 0, ones = 0;
int arr[128][128];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      arr[i][j] == 0 ? zeros++ : ones++;
    }
  }
}

void solve(int size, int dx, int dy) {
  if (size == 1)
    return;

  int nx = dx + size / 2;
  int ny = dy + size / 2;

  bool flag = true;
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { flag = false; }
    }
  }
  if (flag) {
    arr[dx][dy] == 0 ?
      zeros -= size * size - 1 :
      ones -= size * size - 1 ;
    return;
  }

  solve(size / 2, dx, dy);
  solve(size / 2, nx, dy);
  solve(size / 2, dx, ny);
  solve(size / 2, nx, ny);
}

int main() {
  input();
  solve(n, 0, 0);

  cout << zeros << '\n' << ones << '\n';
  return 0;
}

```

[acmicpc.net/problem/2630]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/2630
[월간 코드 챌린지 시즌 1]: https://programmers.co.kr/learn/courses/30/lessons/68936
