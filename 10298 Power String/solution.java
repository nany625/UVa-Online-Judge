import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
            String s;
	        while(st.nextToken() == StreamTokenizer.TT_WORD && !(s = st.sval).equals(".")) {
	            int len = s.length();
    			boolean found = false;
    			for(int i = 1; i <= len / 2 && !found; ++i) {
    				if(len % i == 0) {
    					int j = i;
    					while(j < len && s.substring(0, i).equals(s.substring(j, j + i)))
    						j += i;
    					if(j >= len) {
    						System.out.println(len / i);
    						found = true;
    					}
    				}
    			}
    			if(!found)
    			    System.out.println(1);
	        }
	    } catch(IOException e) {}
	}
}
