fun fizzbuzz(i: Int, x: Int, y: Int): String = when {
  i % x == 0 -> "Fizz";
  i % y == 0 -> "Buzz";
  i % (x * y) == 0 -> "FizzBuzz";
  else -> "$i";
}

fun main(args: Array<String>) {
  val s: String = readLine()!!;
  val xyn: List<String> = s.split(" ".toRegex());

  for (i in 1..xyn[2].toInt()) {
    println(fizzbuzz(i, xyn[0].toInt(), xyn[1].toInt()));
  }
}
