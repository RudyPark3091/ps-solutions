import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
      public int compare(Integer n1, Integer n2) {
        if (Math.abs(n1) > Math.abs(n2))
          return 1;
        else if (Math.abs(n1) == Math.abs(n2)) {
          if (n1 > n2)
            return 1;
          else
            return -1;
        }
        return -1;
      }
    });

    int n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      int t = Integer.parseInt(br.readLine());
      if (t == 0) {
        if (pq.isEmpty())
          bw.write("0\n");
        else
          bw.write(pq.poll() + "\n");
      } else {
        pq.add(t);
      }
    }

    br.close();
    bw.flush();
    bw.close();
  }
}
