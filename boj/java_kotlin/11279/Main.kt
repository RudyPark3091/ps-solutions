import java.util.Collections;
import java.util.PriorityQueue;

fun main(args: Array<String>) {
  var n: Int = readLine()!!.toInt();
  val pq: PriorityQueue<Int> = PriorityQueue<Int> (Collections.reverseOrder());

  for (i in 1..n) {
    var t: Int = readLine()!!.toInt();
    if (t == 0) {
      if (pq.isEmpty())
        println("0");
      else
        println(pq.poll());
    } else {
      pq.add(t);
    }
  }
}
