import java.util.*;

class Solution {
  public String solution(String[] participant, String[] completion) {
    Arrays.sort(participant);
    Arrays.sort(completion);

    String answer = "";

    for (int i = 0; i < completion.length; i++) {
      if (!participant[i].equals(completion[i])) {
        answer = participant[i];
        break;
      }
    }

    if (!participant[participant.length - 1].equals(completion[completion.length - 1]))
      answer = participant[participant.length - 1];

    return answer;
  }
}
