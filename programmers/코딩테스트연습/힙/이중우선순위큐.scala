import scala.collection.mutable.PriorityQueue
import scala.math.Ordering.Implicits._
import util.control.Breaks._

object Solution {
  def greater(x: Int): Int = -1 * x

  def solution(operations: Vector[String]): Vector[Int] = {
    val maxq = new PriorityQueue[Int]()
    val minq = new PriorityQueue[Int]()(Ordering.by(greater))
    var cnt = 0

    for (op <- operations) {
      breakable {
        val ins = op(0) == 'I'
        val num = op.substring(2).toInt
        val dmin = op(2) == '-'

        if (cnt == 0) {
          maxq.dequeueAll
          minq.dequeueAll
        }

        if (ins) {
          minq.enqueue(num)
          maxq.enqueue(num)
          cnt += 1
        } else {
          if (cnt == 0) break
          if (dmin) minq.dequeue()
          else maxq.dequeue()
          cnt -= 1
        }
      }
    }

    val ans = Vector(if (cnt != 0) maxq.head else 0, if (cnt != 0) minq.head else 0)
    ans
  }
}
