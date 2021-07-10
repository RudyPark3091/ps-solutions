fun main() {
  var n: String = readLine()!!;
  var ns: String = "";
  for (i in 0..n.length-3) {
    ns += n[i];
  }
  ns += "00";
  var res: String = "";

  val f: Int = readLine()!!.toInt();

  for (i in 1..99) {
    var num: Int = ns.toInt();
    if (num % f == 0) {
      var s: String = num.toString();
      res = "${s[s.length-2]}${s[s.length-1]}";
      break;
    }
    ns = (num+1).toString();
  }

  println(res);
}
