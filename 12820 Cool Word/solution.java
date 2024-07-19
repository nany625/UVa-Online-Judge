import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval, count = 0;
		    while(n-- > 0) {
		        st.nextToken();
		        String word = st.sval;
		        HashMap<Character, Integer> frequency = new HashMap<>();
		        int len = word.length();
		        for(int i = 0; i < len; ++i) {
		            if(frequency.containsKey(word.charAt(i)))
		                frequency.replace(word.charAt(i), frequency.get(word.charAt(i)) + 1);
		            else
		                frequency.put(word.charAt(i), 1);
		        }
		        if(frequency.size() > 1) {
		            boolean[] ans = new boolean[26];
		            boolean isCool = true;
		            for(Integer i : frequency.values()) {
		                if(!ans[i - 1])
		                    ans[i - 1] = true;
		                else {
		                    isCool = false;
		                    break;
		                }
		            }
		            count += isCool ? 1 : 0;
		        }
		    }
		    output.append("Case " + (++cases) + ": " + count + "\n");
		}
		System.out.print(output);
	}
}
