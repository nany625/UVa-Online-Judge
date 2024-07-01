import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        st.nextToken();
	        int N = (int)st.nval;
	        for(int i = 1; i <= N; ++i) {
    		    System.out.println("Case #" + i + ":");
    		    st.nextToken();
    		    String stockPrice = st.sval;
    		    int min = 0, max = 0, curr = 0;
    		    if(stockPrice.charAt(0) == 'R')
        			min = max = curr++;
        		else if(stockPrice.charAt(0) == 'F')
        			min = max = --curr;
        		int len = stockPrice.length();
    		    for(int j = 1; j < len; ++j) {
    		        if(stockPrice.charAt(j) == 'R')
    		        	max = Math.max(max, curr++);
    		        else if(stockPrice.charAt(j) == 'F')
    		            min = Math.min(min, --curr);
    		        else if(stockPrice.charAt(j) == 'C') {
    			        min = Math.min(min, curr);
    			        max = Math.max(max, curr);
    		        }
    		    }
    		    char[][] graph = new char[max - min + 1][len];
        		int start = max;
        		for(int j = 0; j < len; ++j) {
        		    for(int k = 0; k < max - min + 1; ++k)
        				graph[k][j] = ' ';
        			if(stockPrice.charAt(j) == 'R')
        				graph[start--][j] = '/';
        			else if(stockPrice.charAt(j) == 'F')
        				graph[++start][j] = '\\';
        			else if(stockPrice.charAt(j) == 'C')
        				graph[start][j] = '_';
        		}
        		for(int j = 0; j < max - min + 1; ++j) {
        			len = graph[j].length - 1;
        			while(graph[j][len] == ' ')
        		    	--len;
        			System.out.println("| " + new String(graph[j], 0, len + 1));
        		}
        		System.out.print("+");
        		len = stockPrice.length() + 2;
        		while(len-- > 0)
        			System.out.print("-");
        		System.out.println("\n");
    		}
	    } catch(IOException e) {}
	}
}
