#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> split(string row) {
  istringstream stream(row);
  vector<string> ret;
  string buf;
  while (getline(stream, buf, ' ')) {
    ret.push_back(buf);
  }
  return ret;
}

string enter(string nick) {
  return nick + "님이 들어왔습니다.";
}

string leave(string nick) {
  return nick + "님이 나갔습니다.";
}

vector<string> solution(vector<string> record) {
  map<string, string> id2nick;
  vector<pair<string, bool>> pairs;
  for (int i = 0; i < record.size(); i++) {
    auto row = split(record[i]);
    string action = row[0];
    string id = row[1];
    string nick;
    if (row.size() > 2) nick = row[2];

    if (action == "Enter") {
      id2nick.erase(id);
      id2nick.insert({id, nick});
      pairs.push_back({id, true});
    } else if (action == "Change") {
      id2nick.erase(id);
      id2nick.insert({id, nick});
    } else {
      pairs.push_back({id, false});
    }
  }

  vector<string> answer;
  for (int i = 0; i < pairs.size(); i++) {
    string id = pairs[i].first;
    bool is_enter = pairs[i].second;
    string nick = id2nick.find(id) -> second;
    answer.push_back(is_enter ? enter(nick) : leave(nick));
  }
  return answer;
}

int main() {
  auto tc = solution({
    "Enter uid1234 Muzi",
    "Enter uid4567 Prodo",
    "Leave uid1234",
    "Enter uid1234 Prodo",
    "Change uid4567 Ryan",
  });
  vector<string> ans = {
    "Prodo님이 들어왔습니다.",
    "Ryan님이 들어왔습니다.",
    "Prodo님이 나갔습니다.",
    "Prodo님이 들어왔습니다.",
  };
  for (int i = 0; i < ans.size(); i++) {
    assert(tc[i] == ans[i]);
  }
  return 0;
}
