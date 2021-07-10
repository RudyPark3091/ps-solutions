## Problem
수열이 주어졌을 때, 연속한 부분수열들 중 합이 최대가 되는 경우의 합을 구하라   
##### 입력: 정수 n (1 <= n <= 100000), n개의 정수로 이루어진 수열   
##### 출력: 연속한 부분수열들 중 합이 최대가 되는 경우의 합   
   
## Example
Input ->   
10   
10 -4 3 1 5 6 -35 12 21 -1   
   
Output ->   
33   
   
## Logic Flow
여느 dp문제와 같이 수열을 저장할 배열 arr과 부분합을 계산할 배열 dp를  선언한다.   
이 문제를 어렵게 만드는점은 부분수열이 연속인 인덱스를 가져야 한다는 점이다.   
이는 수열의 원소를 순차적으로 더해나가다 값이 수열의 원소보다 작아지는 지점에서 끊어주는 것으로 해결할 수 있다.   
위 예시에서 차례로 원소들을 더해가면 10, 6, 9, 10, 15, 21, -14, -2, 19, 18 이다.   
하지만 -14의 위치에서, 수열의 원소는 12로 부분합보다 큰 값이다.   
이지점을 기준으로 부분합을 수열의 값 12부터 다시 더해나간다.   
이 방법으로 차례로 원소들을 더해나가면 10, 6, 9, 10, 15, 21, -14, 12, 33, 32 가 되어 우리가 원하는 값은 33이 된다.   
따라서 이 방법으로 수열의 원소들을 순회한 뒤 dp배열의 최댓값을 출력해준다.   
이때 문제의 조건에서 수는 하나 이상 선택해야 한다고 한다.   
만약 이 방법으로 계산한 dp배열의 최댓값이 음수라면 프로그램은 0을 출력할 것이다.   
따라서 이 경우엔 arr배열의 최댓값을 출력한다.   
   
## Source Code   
``` cpp
#include <iostream>
#include <climits>
using namespace std;

int n, maxval = INT_MIN;
int arr[100001];
int dp[100001];

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (maxval < arr[i]) { maxval = arr[i]; }
  }
}

void solve() {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (sum + arr[i] < arr[i]) {
      sum = arr[i];
    } else {
      sum += arr[i];
    }
    dp[i] = sum;
  }

  int max = 0;
  for (int i = 1; i <= n; i++) {
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  if (max <= 0) {
    cout << maxval << '\n';
  } else {
    cout << max << '\n';
  }
}

int main() {
  input();
  solve();

  return 0;
}
```
