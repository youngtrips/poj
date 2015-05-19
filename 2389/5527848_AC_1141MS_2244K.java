import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
      public static void main (String args[]) throws Exception
      {
          BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		  String s1 = stdin.readLine();
		  String s2 = stdin.readLine();
          BigInteger a = new BigInteger(s1);
		  BigInteger b = new BigInteger(s2);
          BigInteger c = a.multiply(b);
		  System.out.println(c.toString());
      }
}
