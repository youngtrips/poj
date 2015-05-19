import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
      public static void main (String args[]) throws Exception
      {
		  Scanner cin = new Scanner(new BufferedInputStream(System.in));
		  int t = cin.nextInt();
		  BigInteger one = new BigInteger("1");
		  BigInteger two = new BigInteger("2");
		  while((t--) != 0)
		  {
			  String s1 = cin.next();
			  String s2 = cin.next();
			  BigInteger a = new BigInteger(s1);
			  BigInteger b = new BigInteger(s2);
			  BigInteger tmp1 = a.add(b);
			  BigInteger tmp2 = b.subtract(a);
			  tmp2 = tmp2.add(one);
			  tmp1 = tmp1.multiply(tmp2);
			  tmp2 = tmp1.divide(two);
			  System.out.println(tmp2.toString());
		  }
      }
}
