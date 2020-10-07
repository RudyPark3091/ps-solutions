## Problem
전봇대가 겹치지 않게 하기 위해 제거해야하는 전깃줄 개수의 최솟값을 출력한다.
##### 입력: 전깃줄의 개수 N (1 <= N <= 100), 전봇대 번호의 쌍   
##### 출력: 제거해야하는 전깃줄 개수의 최솟값   

## Example
input ->   
8   
1 8   
3 9   
2 2   
4 1   
6 4   
10 10   
9 7   
7 6   
output ->   
3   
   
## Logic Flow
전봇대가 겹치지 않으려면 2번 전봇대라인에 연결된 전봇대번호가 단순증가수열이어야 한다.   
그럼 1번 전봇대번호를 기준으로 전봇대번호쌍을 정렬했을때 2번 전봇대수열의 증가하는 부분수열의 최대 길이를 구해야 한다.   
이를 구현하기 위해 필요한것들은 번호 쌍으로 입력받기 위한 pair 클래스, 정렬을 위해 vector를 사용한다.   
입력받은 뒤 2번 전봇대번호 수열에서 증가하는 부분수열의 최대 길이를 구해준 뒤 총 전깃줄 개수에 빼주면 답이 된다.   
   
## Source Code
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a, b;
vector<pair<int, int>> lines;
int dp[100] = { 1, };

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    lines.push_back({a, b});
  }
}

void solve() {
  sort(lines.begin(), lines.end());

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (lines[j].second < lines[i].second) {
        if (dp[j] > cnt) { cnt = dp[j]; }
      }
    }
    dp[i] = cnt + 1;
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < dp[i]) { max = dp[i]; }
  }
  cout << n - max << '\n';
}

int main() {
  input();
  solve();
}
```

