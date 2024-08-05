import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1, s2;
        StringBuilder output = new StringBuilder();
        while((s1 = br.readLine()) != null && (s2 = br.readLine()) != null) {
    	    int len1 = s1.length(), len2 = s2.length();
    	    int[][] L = new int[len1 + 1][len2 + 1];
    	    for(int i = 1; i <= len1; ++i) {
    	        for(int j = 1; j <= len2; ++j) {
    	            if(s1.charAt(i - 1) == s2.charAt(j - 1))
    	                L[i][j] = L[i - 1][j - 1] + 1;
    	            else
    	                L[i][j] = Math.max(L[i - 1][j], L[i][j - 1]);
    	        }
    	    }
    	    output.append(L[len1][len2] + "\n");
    	}
        System.out.print(output);
	}
}
