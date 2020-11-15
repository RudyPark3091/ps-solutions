function solution(participant, completion) {
  participant.sort();
  completion.sort();

  var answer = "";
  for (let i = 0; i < completion.length; i++) {
    if (participant[i] !== completion[i]) {
      answer = participant[i];
      break;
    }
  }

  if (participant[participant.length - 1] !== completion[completion.length - 1])
    answer = participant[participant.length - 1];

  return answer;
}
