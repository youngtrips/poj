import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
      public static void main (String args[]) throws Exception
      {
          BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
          String line = stdin.readLine();
          BigInteger n = new BigInteger(line, 10);
          int s = n.bitCount();
          char buf[] = new char[50000];
          for(int i = 0; i < s; i++) buf[i] = '1';
          String ans = new String(buf, 0, s);
          n = new BigInteger(ans, 2);
          System.out.println(n.toString());
      }
}
