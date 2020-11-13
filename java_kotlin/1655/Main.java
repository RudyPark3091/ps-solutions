import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    PriorityQueue<Integer> minq = new PriorityQueue<> ();
    PriorityQueue<Integer> maxq = new PriorityQueue<> (Collections.reverseOrder());

    int n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      int t = Integer.parseInt(br.readLine());

      if (minq.size() == maxq.size())
        maxq.add(t);
      else
        minq.add(t);

      if (!maxq.isEmpty() && !minq.isEmpty()) {
        if (maxq.peek() > minq.peek()) {
          int maxtp = maxq.poll();
          int mintp = minq.poll();

          maxq.add(mintp);
          minq.add(maxtp);
        }
      }

      bw.write(maxq.peek() + "\n");
    }

    br.close();
    bw.flush();
    bw.close();
  }
}
