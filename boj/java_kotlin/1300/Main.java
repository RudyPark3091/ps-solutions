import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    int n, k;
    int res = 0;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    k = sc.nextInt();

    int a = 1;
    int b = k;

    int mid = 0;
    int cnt = 0;

    while (a <= b) {
      mid = (a + b) / 2;
      cnt = 0;
      for (int i = 1; i <= n; i++) {
        cnt += Math.min(mid / i, n);
      }

      if (cnt < k) {
        a = mid + 1;
      } else {
        b = mid - 1;
        res = mid;
      }
    }

    System.out.println(res);
  }

}
