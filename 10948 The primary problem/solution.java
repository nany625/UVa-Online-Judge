import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
    		output.append(N).append(":\n");
    		if(N == 4)
    		    output.append("2+2\n");
    		else if((N & 1) == 1) {
                if(!isComposite[N - 2 >> 1])
                    output.append("2+").append(N - 2).append('\n');
                else
                    output.append("NO WAY!\n");
            } else {
                int i = 3, j = N - 3;
                while(i <= j) {
                    if(!isComposite[i >> 1] && !isComposite[j >> 1])
                        break;
                    i += 2;
                    j -= 2;
                }
                if(i <= j)
                    output.append(i).append('+').append(j).append('\n');
                else
                    output.append("NO WAY!\n");
            }
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
