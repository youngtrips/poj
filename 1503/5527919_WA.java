import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
      public static void main (String args[]) throws Exception
      {
          BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		  BigInteger a = new BigInteger("0");
		  while(true)
		  {
			  String s = stdin.readLine();
			  if(s.charAt(0) == '0') break;
			  BigInteger b = new BigInteger(s);
			  a = a.add(b);
		  }
		  System.out.println(a.toString());
      }
}
