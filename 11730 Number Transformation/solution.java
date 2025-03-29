import java.io.*;
import java.util.*;

public class Main {
    static short[] primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
        127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
        179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
        233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
        283, 293, 307, 311, 313, 317, 331
    };
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, S;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) != 0) {
            st.nextToken();
            int T = (int)st.nval;
            if(S == T)
                output.append("Case ").append(++cases).append(": 0\n");
            else {
                ArrayList<Short> curr = new ArrayList<>();
                curr.add((short)S);
                int step = 1;
                boolean[] visited = new boolean[T + 1];
                boolean found = false;
                while(!curr.isEmpty() && !found) {
                    ArrayList<Short> next = new ArrayList<>();
                    for(Short s : curr) {
                        for(int i = 0; i < 67 && primes[i] < s && !found; ++i) {
                            if(s % primes[i] == 0) {
                                if(s + primes[i] == T) {
                                    output.append("Case ").append(++cases).append(": ").append(step).append('\n');
                                    found = true;
                                } else if(s + primes[i] < T && !visited[s + primes[i]]) {
                                    next.add((short)(s + primes[i]));
                                    visited[s + primes[i]] = true;
                                }
                            }
                        }
                    }
                    curr = new ArrayList<>(next);
                    ++step;
                }
                if(!found)
                    output.append("Case ").append(++cases).append(": -1\n");
            }
    	}
        System.out.print(output);
	}
}
