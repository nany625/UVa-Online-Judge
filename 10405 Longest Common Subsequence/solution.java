import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1, s2;
        StringBuilder output = new StringBuilder();
        while((s1 = br.readLine()) != null && (s2 = br.readLine()) != null) {
    	    int[] L = new int[s2.length() + 1];
    	    for(int i = 0; i < s1.length(); ++i) {
    	        int prev = 0;
    	        for(int j = 1; j <= s2.length(); ++j) {
    	            int temp = L[j];
    	            if(s1.charAt(i) == s2.charAt(j - 1))
    	                L[j] = prev + 1;
    	            else
    	                L[j] = Math.max(L[j], L[j - 1]);
    	            prev = temp;
    	        }
    	    }
    	    output.append(L[s2.length()]).append('\n');
    	}
        System.out.print(output);
	}
}
