import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
	    StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
	        String N = br.readLine();
    		int len = N.length();
    		short[] modThreeCount = new short[3];
    		for(int j = 0; j < len; ++j)
    			++modThreeCount[(N.charAt(j) - '0') % 3];
    		short result = (short)((modThreeCount[1] + modThreeCount[2] * 2) % 3);
    		if(result == 0)
    			output.append("Case " + i + (modThreeCount[0] % 2 == 1 ? ": S\n" : ": T\n"));
    		else
    			output.append("Case " + i + (modThreeCount[result] != 0 && modThreeCount[0] % 2 == 0 ? ": S\n" : ": T\n"));
    	}
	    System.out.print(output);
	}
}
