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
    		short[] modThreeCount = new short[3];
    		for(int j = 0; j < N.length(); ++j)
    			++modThreeCount[(N.charAt(j) - '0') % 3];
    		short result = (short)((modThreeCount[1] + (modThreeCount[2] << 1)) % 3);
    		if(result == 0)
    			output.append("Case ").append(i).append((modThreeCount[0] & 1) == 1 ? ": S\n" : ": T\n");
    		else
    			output.append("Case ").append(i).append(modThreeCount[result] != 0 && (modThreeCount[0] & 1) == 0 ? ": S\n" : ": T\n");
    	}
	    System.out.print(output);
	}
}
