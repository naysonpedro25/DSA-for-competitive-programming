package string;
import java.util.Scanner;
// https://neps.academy/br/exercise/389
public class LinguaDoP {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String txt = sc.nextLine();
    StringBuilder sb = new StringBuilder();

    String[] ps = txt.split(" ");
    for(String ms : ps){
      for(int i = 0; i < ms.length(); i++){
        if(i % 2 != 0){
          sb.append(ms.charAt(i));
        }
      }
      sb.append(" ");
    }

    System.out.println(sb.toString());
    sc.close();
  }
}