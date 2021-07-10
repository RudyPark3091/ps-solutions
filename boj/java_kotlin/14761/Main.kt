fun fizzbuzz(i: Int, x: Int, y: Int): String {
  var ret: String = "";
  if (i % x == 0)
    ret += "Fizz";
  if (i % y == 0)
    ret += "Buzz";
  if (i % x != 0 && i % y != 0)
    ret = "$i";

  return ret;
}

fun main(args: Array<String>) {
  val s: String = readLine()!!;
  val xyn: List<String> = s.split(" ".toRegex());

  for (i in 1..xyn[2].toInt()) {
    println(fizzbuzz(i, xyn[0].toInt(), xyn[1].toInt()));
  }
}
