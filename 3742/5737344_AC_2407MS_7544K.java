import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
	public static void main (String args[]) throws Exception
	{
		BigInteger[][] c;
		BigInteger[] a;
		BigInteger[] b;
		BigInteger one = new BigInteger("1");
		BigInteger k   = new BigInteger("0");
		BigInteger tmp = new BigInteger("0");
		c = new BigInteger[201][201];
		int i, j, n, t;
		for(i = 0;i <= 200; i++)
		{
			c[i][0] = one;
			c[i][i] = one;
		}
		for(i = 1;i <= 200; i++)
		{
			for(j = 1;j < i; j++)
			{
				tmp = tmp.valueOf(0);
				tmp = tmp.add(c[i-1][j-1]);
				tmp = tmp.add(c[i-1][j]);
				c[i][j] = tmp;
			}
		}
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		while(true)
		{
			n = stdin.nextInt();
			t = stdin.nextInt();
			a = new BigInteger[201];
			b = new BigInteger[201];
			for(i = 0;i <= n; i++)
			{
				String s = stdin.next();
				a[i] = new BigInteger(s);
			}
			b[n] = a[n];
			for(i = n - 1;i >= 0; i--)
			{
				b[i] = a[i];
				BigInteger sum = new BigInteger("0");
				for(j = i + 1;j <= n; j++)
				{
					tmp = tmp.valueOf(1);
					tmp = tmp.multiply(b[j]);
					tmp = tmp.multiply(c[j][j - i]);
					k   = k.valueOf(-t);
					k 	= k.pow(j-i);
					tmp = tmp.multiply(k);
					sum = sum.add(tmp);
					
				}
				b[i] = b[i].subtract(sum);
			}
			for(i = 0;i < n; i++) System.out.print(b[i].toString() + " ");
			System.out.println(b[n].toString());
			if(stdin.hasNext() == false) break;
		}
	}
}
