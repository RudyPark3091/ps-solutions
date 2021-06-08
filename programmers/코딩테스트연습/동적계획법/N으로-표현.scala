object Solution {
  def solution(N: Int, number: Int): Int = {
    if (N == number) return 1

    val dp =
      for (i <- 1 to 8)
        yield scala.collection.mutable.Set[Int](
          (for (_ <- 0 until i) yield N).mkString("").toInt
        )

    for (i <- 0 until 8) {
      for (j <- 0 until i) {
        for (x <- dp(j)) {
          for (y <- dp(i - j - 1)) {
            dp(i) += x * y
            dp(i) += x - y
            dp(i) += x + y
            if (y != 0) dp(i) += x / y
          }
        }
      }
      if (dp(i).contains(number)) return i + 1
    }
    -1
  }

  def main(args: Array[String]) {
    println (solution(5, 12))
  }
}
