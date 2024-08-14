import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1, s2;
        StringBuilder output = new StringBuilder();
        while((s1 = br.readLine()) != null && (s2 = br.readLine()) != null) {
    	    int len1 = s1.length(), len2 = s2.length();
    	    int[] L = new int[len2 + 1];
    	    for(int i = 0; i < len1; ++i) {
    	        int prev = 0;
    	        for(int j = 1; j <= len2; ++j) {
    	            int temp = L[j];
    	            if(s1.charAt(i) == s2.charAt(j - 1))
    	                L[j] = prev + 1;
    	            else
    	                L[j] = Math.max(L[j], L[j - 1]);
    	            prev = temp;
    	        }
    	    }
    	    output.append(L[len2] + "\n");
    	}
        System.out.print(output);
	}
}
