import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    int limit = (int)Math.sqrt(n);
		    long res = 0;
		    int[] quotients = new int[limit + 1];
    		for(int i = 1; i <= limit; ++i) {
    			quotients[i] = n / i;
    			res += quotients[i];
    		}
    		for(int i = 1; i < limit; ++i)
    			res += (long)i * (quotients[i] - quotients[i + 1]);
    		if(limit != quotients[limit])
    			res += (long)limit * (quotients[limit] - (n / (limit + 1)));
    		output.append(res).append('\n');
		}
		System.out.print(output);
	}
}
