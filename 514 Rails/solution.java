import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int prev;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (prev = (int)st.nval) != 0) {
                int max = prev;
                boolean YES = true;
                for(int i = 1; i < N; ++i) {
                    st.nextToken();
                    int curr = (int)st.nval;
                    if(YES) {
                        if(curr > prev && curr < max)
                            YES = false;
                        else {
                            prev = curr;
                            max = Math.max(max, curr);
                        }
                    }
                }
                output.append(YES ? "Yes\n" : "No\n");
            }
            output.append('\n');
    	}
        System.out.print(output);
	}
}
