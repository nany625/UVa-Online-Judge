import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        while(st.nextToken() == StreamTokenizer.TT_WORD) {
	            String s = st.sval;
	            st.nextToken();
	            String t = st.sval;
	            int i = 0, j = 0, lens = s.length(), lent = t.length();
	            while(j < lent) {
    		        if(s.charAt(i) == t.charAt(j))
    		            ++i;
    		        if(i == lens) {
    		            System.out.println("Yes");
    		            break;
    		        }
    		        ++j;
    		    }
    		    if(i < lens)
    		        System.out.println("No");
	        }
	    } catch(IOException e) {}
	}
}
