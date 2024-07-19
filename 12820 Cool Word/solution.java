import java.io.*;

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
		        int[] frequency = new int[26];
		        int len = word.length();
		        for(int i = 0; i < len; ++i)
		            ++frequency[word.charAt(i) - 'a'];
		        boolean[] ans = new boolean[30];
		        boolean isCool = true;
                int found = 0, diff = 0;
                for(int i = 0; i < 26 && found < len && isCool; ++i) {
                    if(frequency[i] > 0) {
                        if(!ans[frequency[i] - 1]) {
                            ans[frequency[i] - 1] = true;
                            found += frequency[i];
                            ++diff;
                        } else
                            isCool = false;
                    }
                }
                count += (isCool && diff > 1 ? 1 : 0);
		    }
		    output.append("Case " + (++cases) + ": " + count + "\n");
		}
		System.out.print(output);
	}
}
