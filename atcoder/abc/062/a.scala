import java.util.Scanner

object Main {

  val scan = new Scanner(System.in)

  def main(args: Array[String]) {
    val a, b = scan.nextInt;
    if (f(a) == f(b)) {
      println("Yes")
    } else {
      println("No")
    }
  }

  def f(a: Int): Int = {
    a match {
      case 2 => 0
      case 4 | 6 | 9 | 11 => 1
      case _ => 2;
    }
  }
}
