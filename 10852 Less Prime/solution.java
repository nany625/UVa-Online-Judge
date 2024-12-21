import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 5003;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int M = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(M-- > 0) {
		    st.nextToken();
		    short N = (short)st.nval;
		    N >>= 1;
		    ++N;
		    N += ((N & 1) == 0 ? 1 : 0);
		    while(isComposite[N >> 1])
                N += 2;
            output.append(N).append('\n');
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
		for(short n = 3; n <= MAX_NUM; n += 2) {
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
