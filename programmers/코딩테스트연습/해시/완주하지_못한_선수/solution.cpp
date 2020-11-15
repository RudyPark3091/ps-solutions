#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());

  string answer = "";
  for (int i = 0; i < completion.size(); i++) {
    if (participant[i] != completion[i]) {
      answer = participant[i];
      break;
    }
  }

  if (participant.back() != completion.back())
    answer = participant.back();

  return answer;
}

