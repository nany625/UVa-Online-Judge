import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
    	    int max = 0, currMax = 0;
    	    while(N-- > 0) {
    	        st.nextToken();
    	        int temp = (int)st.nval;
    	        currMax = Math.max(temp, currMax + temp);
    	        max = Math.max(max, currMax);
    	    }
    	    if(max > 0)
    	        output.append("The maximum winning streak is ").append(max).append(".\n");
    	    else
    	        output.append("Losing streak.\n");
    	}
        System.out.print(output);
	}
}
