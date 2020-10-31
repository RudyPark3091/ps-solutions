## Problem
[acmicpc.net/problem/10816]
   
## Example
input ->   
10   
6 3 2 10 10 10 -10 -10 7 3   
8   
10 9 -5 2 3 4 5 -10   
   
output ->   
3 0 0 1 2 0 0 2   
   
## Logic
이 문제는 단순 이진 탐색에 추가 작업이 필요하다.   
[1920번 문제]와 비슷하지만 주어진 수가 배열 내에 몇 개나 있는지 알아내기 위해 탐색 성공시에 연산을 추가한다.   
탐색이 성공한다면 midpoint 왼쪽으로 다시 이진탐색을 하여 해당 숫자의 lower bound를 알아낸다.   
오른쪽으로도 탐색을 해 해당 숫자의 upper bound를 알아낸다.   
그럼 배열 내에 존재하는 숫자의 개수는 `upper bound - lower bound` 가 되므로 이를 출력하면 된다.   
   
...   
   
인줄 알았으나, 아무리 시도해도 시간 초과를 받았다.   
알아보던 중, 그냥 길이 20,000,001의 배열을 선언해서 풀어도 간단히 풀리는 문제임을 알아냈다.   
또한 이미 STL에 lower_bound, upper_bound 함수가 제공되고 있는 것도 알게 되었다.   
여러 모로 어이없는 문제였다.   
   
## Source Code
``` cpp
#include <cstdio>
#define NUM 10000000
using namespace std;

int n, m;
int arr[2 * NUM + 1] = { 0 };

void input() {
  int t;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    arr[t + NUM]++;
  }
}

void solve(int target) {
  printf("%d ", arr[target + NUM]);
}

int main() {
  int t;
  input();

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    solve(t);
  }
  return 0;
}
```
   

[acmicpc.net/problem/10816]: https://www.acmicpc.net/problem/10816
[1920번 문제]: https://www.acmicpc.net/problem/1920
