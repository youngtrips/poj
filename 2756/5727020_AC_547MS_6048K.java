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
			  String s1 = cin.next();
			  String s2 = cin.next();
			  s1 = s1.replace('+', '0');
			  s2 = s2.replace('+', '0');
			  BigInteger a = new BigInteger(s1);
			  BigInteger b = new BigInteger(s2);
			  a = a.add(b);
			  System.out.println(a.toString());
		  }
      }
}

