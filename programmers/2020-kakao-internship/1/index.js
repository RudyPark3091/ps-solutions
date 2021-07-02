function solution(numbers, hand) {
  const isLeftHand = hand === 'left';
  const dist = (a, b) => Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
  const coords = [
    [3, 1],
    [0, 0],
    [0, 1],
    [0, 2],
    [1, 0],
    [1, 1],
    [1, 2],
    [2, 0],
    [2, 1],
    [2, 2],
  ]

  let thumbLeft = [3, 0];
  let thumbRight = [3, 2];

  let answer = '';

  numbers.forEach((num) => {
    switch (num) {
      // handle thumbLeft
      case 1:
      case 4:
      case 7:
        answer += 'L';
        thumbLeft = coords[num];
        break;

      // handle thumbRight
      case 3:
      case 6:
      case 9:
        answer += 'R';
        thumbRight = coords[num];
        break;

      // handle 2, 5, 8, 0
      default:
        const distLeft = dist(thumbLeft, coords[num]);
        const distRight = dist(thumbRight, coords[num]);

        if (distLeft === distRight) {
          if (isLeftHand) {
            answer += 'L';
            thumbLeft = coords[num];
          } else {
            answer += 'R';
            thumbRight = coords[num];
          }
        } else if (distLeft > distRight) {
          answer += 'R';
          thumbRight = coords[num];
        } else {
          answer += 'L';
          thumbLeft = coords[num];
        }
    }
  });

  return answer;
}
