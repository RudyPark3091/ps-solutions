import java.util.Scanner;

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int probs = 0;
    int[] arr = new int[3];

    for (int i = 0; i < n; i++) {
      int yes = 0;
      for (int j = 0; j < 3; j++) {
        arr[j] = sc.nextInt();
        if (arr[j] == 1)
          yes++;
      }

      if (yes >= 2)
        probs++;
    }

    System.out.println(probs);
  }
}
