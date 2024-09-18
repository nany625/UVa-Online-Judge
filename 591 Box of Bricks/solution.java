import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int set = 0, n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
    	    short[] h = new short[n];
    	    short total = 0;
    	    for(int i = 0; i < n; ++i) {
    	        st.nextToken();
    	        h[i] = (short)st.nval;
    	        total += h[i];
    	    }
    	    total /= n;
    	    short moves = 0;
    	    for(Short s : h) {
    	        if(s > total)
    	            moves += s - total;
    	    }
    	    output.append("Set #").append(++set).append("\nThe minimum number of moves is ").append(moves).append(".\n\n");
    	}
        System.out.print(output);
	}
}
