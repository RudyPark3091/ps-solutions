fun main(args: Array<String>) {
  val n: Int = readLine()!!.toInt();
  var x: Int = 0;

  for (i in 1..n) {
    val s: String = readLine()!!;
    if (s == "++X" || s == "X++") {
      x++;
    } else {
      x--;
    }
  }

  println(x);
}
