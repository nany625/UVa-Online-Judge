  import java.io.*;
import java.util.*;

public class Main {
    static boolean[] isComposite = new boolean[332];
    static short[] primes = new short[67];
    static int count = 1;
	public static void main(String[] args) throws IOException {
	    primes[0] = 2;
	    for(short i = 3; count < 67; i += 2) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 31) {
                    for(short j = (short)(i * i); j <= 331; j += i)
                        isComposite[j] = true;
                }
            }
        }
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, S, T;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (T = (int)st.nval) != 0) {
            if(S == T) {
                output.append("Case ").append(++cases).append(": 0\n");
                continue;
            }
            ArrayList<Short> trans = new ArrayList<>();
            trans.add((short)S);
            int step = 1;
            boolean[] visited = new boolean[T + 1];
            boolean found = false;
            while(!trans.isEmpty() && !found) {
                ArrayList<Short> nextTrans = new ArrayList<>();
                for(Short s : trans) {
                    for(int i = 0; i < 67 && primes[i] < s && !found; ++i) {
                        if(s % primes[i] == 0) {
                            if(s + primes[i] == T) {
                                output.append("Case ").append(++cases).append(": ").append(step).append('\n');
                                found = true;
                            } else if(s + primes[i] < T && !visited[s + primes[i]]) {
                                nextTrans.add((short)(s + primes[i]));
                                visited[s + primes[i]] = true;
                            }
                        }
                    }
                }
                trans = new ArrayList<>(nextTrans);
                ++step;
            }
            if(!found)
                output.append("Case ").append(++cases).append(": -1\n");
    	}
        System.out.print(output);
	}
}
