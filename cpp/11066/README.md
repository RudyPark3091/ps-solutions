## Problem
[acmicpc.net/problem/11066]  
  
## Example
input ->  
2  
4  
40 30 30 50  
15  
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32  
  
output ->  
300  
864  
  
## Logic
i번째 파일부터 j번째 파일까지를 합칠때 드는 비용을 dp_i,j 라고 한다면, `dp_i,j = min(k=i to k=j){ dp_i,k + dp_k+1,j } + (cost sum i to j)`으로 쓸 수 있다.  
이를 2차원 배열로 치환해 생각하면 `dp[i][j] = min(dp[i][k] + dp[k+1][j]) + sum[j] - sum[i]`의 점화식을 얻을 수 있다.  
이때 dp는 k * k의 2차원 배열, sum은 길이 k의 1차원 배열이다.  
k를 i에서 j까지 순회하며 minimum값을 얻는다.  
  
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int t, k;
int arr[501] = { 0 };
int dp[501][501] = { 0 };
int sum[501];

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> arr[j];
      sum[j] = sum[j-1] + arr[j];
    }

    for (int x = 1; x < k; x++) {
      for (int y = 1; x + y <= k; y++) {
        int z = x + y;
        dp[y][z] = __INT_MAX__;

        for (int w = y; w < z; w++) {
          dp[y][z] = min(dp[y][z], dp[y][w] + dp[w+1][z] + sum[z] - sum[y - 1]);
        }
      }
    }

    cout << dp[1][k] << '\n';
  }
  return 0;
}
```
  
## Review
정말 이런문제는 너무 어렵다.  
알고리즘 수업시간에 비슷한 문제를 풀었지만 인터넷을 봐가며 겨우겨우 이해했다.  
아직 갈길이 멀다.  

[acmicpc.net/problem/11066]: https://acmicpc.net/problem/11066
