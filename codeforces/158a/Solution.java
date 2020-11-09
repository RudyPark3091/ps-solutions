import java.util.Scanner;

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int man = 0;
    int[] arr = new int[50];

    int n = sc.nextInt();
    int k = sc.nextInt();
    for (int i = 0; i < n; i++)
      arr[i] = sc.nextInt();

    for (int i = 0; i < n; i++) {
      if (arr[i] >= arr[k - 1] && arr[i] > 0)
        man++;
    }

    System.out.println(man);
  }
}
