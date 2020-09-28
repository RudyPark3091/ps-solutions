## Problem
수열 A가 주어졌을 때 가장 긴 증가하는 부분 수열을 구한다.   
##### 입력: 수열의 크기 N(1 <= N <= 1000), 수열의 원소들   
##### 출력: 가장 긴 증가하는 부분 수열의 길이   

## Example
input ->   
6   
10 20 10 30 20 50   
output ->   
4   
   
## Logic Flow
수열을 입력받을 배열, 부분수열의 길이를 저장할 배열을 선언한다.   
입력받은 수열의 원소를 하나씩 검사한다.   
각 검사에 대해 dp배열의 첫번째 원소부터 순회한다.   
dp배열에 저장할 값은 0부터 시작한다.   
순회중에 수열의 원소가 대응하는 수열 원소보다 크고, 해당 dp값이 현재 카운트값보다 크면 카운트 값에 dp값을 저장한다.   
순회가 끝나면 dp배열의 최댓값이 가장 긴 증가하는 부분 수열의 길이가 된다.   
최댓값을 출력한다.   
   
## Source Code
``` cpp
#include <iostream>
using namespace std;

int n;
int a[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        if (dp[j] > cnt) { cnt = dp[j]; }
      }
    }
    dp[i] = cnt + 1;
  }

  int max = 0;
  for (int i = 1; i <=n; i++) {
    if (max < dp[i]) { max = dp[i]; }
  }
  cout << max << '\n';

  return 0;
}
```
