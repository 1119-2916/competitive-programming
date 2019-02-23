object Main {
  val s = new java.util.Scanner(System.in)
  def main(args: Array[String]) {
    val x, y = s.nextInt;
    println(if(group(x)==group(y))"Yes"else"No");
  }
  def group(v: Int): Int = {
    v match {
      case 2 => 1
      case 4 | 6 | 9 | 11 => 2
      case _ => 0;
    }
  }
}

