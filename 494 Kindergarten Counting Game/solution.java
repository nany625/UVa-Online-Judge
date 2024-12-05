import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        StringBuilder output = new StringBuilder();
        while((s = br.readLine()) != null) {
    	    s.trim();
    	    int count = 0, i = 0;
    		while(i < s.length()) {
    			if(Character.isLetter(s.charAt(i))) {
    				int j = i + 1;
    				while(j < s.length() && Character.isLetter(s.charAt(j)))
    					++j;
					++count;
    				i = j;
    			}
    			++i;
    		}
    		output.append(count).append('\n');
    	}
        System.out.print(output);
	}
}
