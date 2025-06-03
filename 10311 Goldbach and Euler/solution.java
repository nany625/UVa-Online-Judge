import java.io.*;
import java.util.*;

public class Main {
    static int MAXN = 100000000;
    static boolean[] isComposite = new boolean[(MAXN >> 1) + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            if(n <= 4)
                output.append(n).append(" is not the sum of two primes!\n");
            else {
                if((n & 1) == 1) {
                    if(isComposite[n - 2 >> 1])
                        output.append(n).append(" is not the sum of two primes!\n");
                    else
                        output.append(n).append(" is the sum of 2 and ").append(n - 2).append(".\n");
                } else {
                    int temp = n - 1 >> 1;
                    if((temp & 1) == 0)
                        --temp;
                    while(temp >= 3 && (isComposite[temp >> 1] || isComposite[n - temp >> 1]))
                        temp -= 2;
                    if(temp >= 3)
                        output.append(n).append(" is the sum of ").append(temp).append(" and ").append(n - temp).append(".\n");
                    else
                        output.append(n).append(" is not the sum of two primes!\n");
                }
            }
        }
		System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 3; n <= MAXN; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 0, temp; (temp = primes.get(i) * n) <= MAXN; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
