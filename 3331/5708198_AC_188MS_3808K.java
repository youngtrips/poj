import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
      public static void main (String args[]) throws Exception
      {
		  Scanner cin = new Scanner(new BufferedInputStream(System.in));
		  int t = cin.nextInt();
		  for(int i = 1;i <= t; i++)
		  {
			  int x = cin.nextInt();
			  int y = cin.nextInt();
			  BigInteger f = new BigInteger("1");
			  for(int j = 2;j <= x; j++)
			  {
				  Integer tmp1 = j;
				  String tmp2 = tmp1.toString();
				  BigInteger tmp3 = new BigInteger(tmp2);
				  f = f.multiply(tmp3);
			  }
			  String s = f.toString();
			  int cnt = 0;
			  for(int j = 0;j < s.length(); j++)
			  {
				  if((s.charAt(j) - '0') == y) cnt++;
			  }
			  System.out.println(cnt);
		  }
      }
}
