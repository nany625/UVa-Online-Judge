// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            st.nextToken();
            int c = (int)st.nval;
            st.nextToken();
            int d = (int)st.nval;
            st.nextToken();
            int L = (int)st.nval;
            if(a == 0 && b == 0 && c == 0 && d == 0 && L == 0)
                break;
            int count = 0, limit = Math.min(d - 1, L);
    	    for(int x = 0; x <= limit; ++x) {
    	        if((a * x * x + b * x + c) % d == 0)
    	            count += (L - x) / d + 1;
    	    }
    	    output.append(count).append('\n');
        }
        System.out.print(output);
	}
}

// #解法二
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            st.nextToken();
            int c = (int)st.nval;
            st.nextToken();
            int d = (int)st.nval;
            st.nextToken();
            int L = (int)st.nval;
            if(a == 0 && b == 0 && c == 0 && d == 0 && L == 0)
                break;
            int count = 0;
    	    for(int x = 0; x <= L; ++x) {
    	        if((a * x * x + b * x + c) % d == 0)
    	            ++count;
    	    }
    	    output.append(count).append('\n');
        }
        System.out.print(output);
	}
}
