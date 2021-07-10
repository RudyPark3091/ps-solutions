## Problem
[acmicpc.net/problem/5430]   
   
## Example
input ->   
4   
RDD   
4   
[1,2,3,4]   
DD   
1   
[42]   
RRD   
6   
[1,1,2,3,5,8]   
D   
0   
[]   
   
## Logic
이 문제는 정답 비율이 20퍼센트로 정말 낮다.   
얼핏 보기에 간단해 보이지만 아주 많은 예외처리를 필요로 하기 때문이다.   
문제는 단순하다.   
R이 들어오면 배열을 뒤집고, D가 들어오면 배열의 첫 항목을 삭제한다. 만약 삭제할 수 없다면 error를 출력한다.   
중요한것은 R이 들어온다고 단순히 배열을 뒤집는 것이 아니라 배열을 뒤집은 효과를 주는 것이다.   
R이 들어오면 bool 변수 reverse를 토글해주며 D가 들어올때마다 pop_back 또는 pop_front를 해준다.   
여기서 실수하기 쉬운 상황들을 몇가지 뽑아보면,   
* 입력배열이 아무것도 없는 배열일때:   
  * 아무것도 없는 배열에서 R이 들어오면 아무것도 없는 배열을 출력해야 한다.   
  * 아무것도 없는 배열에서 D가 들어오면 error를 출력한다.   
* 배열안의 원소는 한자리수가 아니다:
  * 배열을 입력받을 때 파싱에 주의해야한다.   
  * 만약 대괄호 []을 기준으로 배열의 원소를 입력받는다면 여기서 큐 안에 대괄호가 딸려들어갈 수 있다.   
문제는 단순하지만 모든 상황을 완벽하게 고려해야 정답을 받을 수 있는 문제이다.   
   
## Source Code
``` cpp
#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  
  for (int tc = 0; tc < t; tc++) {
    deque<int> q;
    string p;
    bool error = false;
    bool reverse = false;
    int n = 0;

    cin >> p;
    cin >> n;

    string a, buf;
    cin >> a;
    istringstream str(a);

    while (getline(str, buf, ',')) {
      if (buf == "[]") { q.clear(); }
      else if (buf.front() == '[') {
        if (buf.back() == ']') {
          buf.erase(buf.size() - 1);
        }
        q.push_back(stoi(buf.substr(1)));
      }
      else if (buf.back() == ']') { q.push_back(stoi(buf.substr(0, buf.size() -1 ))); }
      else { q.push_back(stoi(buf)); }
    }

    for (int i = 0; i < p.length(); i++) {
      if (p.at(i) == 'R') {
        reverse = !reverse;
      } else if (p.at(i) == 'D') {
        if (q.empty()) {
          cout << "error\n";
          error = true;
          break;
        } else {
          if (reverse) {
            q.pop_back();
          } else {
            q.pop_front();
          }
        }
      }
    }

    if (!error) {
      cout << '[';
      if (!reverse) {
        if (q.size() != 0) {
          for (int i = 0; i < q.size() - 1; i++) { cout << q.at(i) << ','; }
          cout << q.at(q.size() - 1) << "]\n";
        } else {
          cout << "]\n";
        }
      } else {
        if (q.size() != 0) {
          for (int i = q.size() - 1; i > 0; i--) {
            cout << q.at(i) << ',';
          }
          cout << q.at(0) << "]\n";
        } else {
          cout << "]\n";
        }
      }
    }
  }

  return 0;
}

```
   
## Review
처음 제출한 코드들은 queue의 item타입을 string으로 하여 제출했다.   
이후 queue의 item타입을 int로 바꾸고 stoi 함수를 사용한 결과 메모리 사용이 거의 2배정도 차이가 났다.   
이를 기억하여 최적화 과정에서 이용하도록 하자.   
   
