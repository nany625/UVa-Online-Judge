import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        int n = 0;
        int[] correct = new int[1], student = new int[1];
        int[][] L = new int[1][1];
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
    	    String[] tokens = line.split("\\s+");
    	    int len = tokens.length;
    	    if(len == 1) {
    	        n = Integer.parseInt(tokens[0]);
    	        correct = new int[n];
    	        for(int i = 1; i <= n; ++i) {
    	            st.nextToken();
    	            correct[(int)st.nval - 1] = i;
    	        }
    	        L = new int[n + 1][n + 1];
    	    } else {
    	        student = new int[n];
    	        for(int i = 0; i < n; ++i)
    	            student[Integer.parseInt(tokens[i]) - 1] = i + 1;
    	        for(int i = 1; i <= n; ++i) {
                    for(int j = 1; j <= n; ++j) {
                        if(correct[i - 1] == student[j - 1])
                            L[i][j] = L[i - 1][j - 1] + 1;
                        else
                            L[i][j] = Math.max(L[i - 1][j], L[i][j - 1]);
                    }
                }
                output.append(L[n][n] + "\n");
    	    }
    	}
        System.out.print(output);
	}
}
