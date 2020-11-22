fun main(args: Array<String>) {
  val s1: String = readLine()!!.toLowerCase();
  val s2: String = readLine()!!.toLowerCase();

  for (i in 0..s1.length-1) {
    if (s1[i] != s2[i]) {
      if (s1[i] > s2[i]) {
        println(1);
        return;
      } else if (s1[i] < s2[i]) {
        println(-1);
        return;
      }
    }
  }

  println(0);
}
