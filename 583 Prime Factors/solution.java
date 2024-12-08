import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 46340;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int g;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (g = (int)st.nval) != 0) {
            output.append(g).append(" = ");
            boolean firstFactor = true;
            if(g < 0) {
                output.append("-1");
                g *= -1;
                firstFactor = false;
            }
            int limit = (int)Math.sqrt(g);
            for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
                if(g % primes.get(i) == 0) {
                    do {
                        if(!firstFactor)
                            output.append(" x ");
                        output.append(primes.get(i));
                        g /= primes.get(i);
                        firstFactor = false;
                    } while(g % primes.get(i) == 0);
                    limit = (int)Math.sqrt(g);
                }
            }
            if(g > 1) {
                if(!firstFactor)
                    output.append(" x ");
                output.append(g);
            }
            output.append('\n');
        }
        System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add(2);
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
