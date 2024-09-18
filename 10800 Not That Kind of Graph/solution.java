import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    st.nextToken();
        int N = (int)st.nval;
	    StringBuilder output = new StringBuilder();
	    for(int i = 1; i <= N; ++i) {
    	    output.append("Case #").append(i).append(":\n");
    	    st.nextToken();
    	    String stockPrice = st.sval;
    	    int min = 0, max = 0, curr = 0;
    	    switch(stockPrice.charAt(0)) {
                case 'R':
    			    min = max = curr++;
                    break;
    		    case 'F':
    			    min = max = --curr;
            }
    		int len = stockPrice.length();
    	    for(int j = 1; j < len; ++j) {
                switch(stockPrice.charAt(j)) {
    	            case 'R':
    	        	    max = Math.max(max, curr++);
                        break;
    	            case 'F':
    	                min = Math.min(min, --curr);
                        break;
    	            case 'C':
    		            min = Math.min(min, curr);
    		            max = Math.max(max, curr);
    	        }
    	    }
    	    char[][] graph = new char[max - min + 1][len];
    		int start = max;
    		for(int j = 0; j < len; ++j) {
    		    for(int k = 0; k < max - min + 1; ++k)
    				graph[k][j] = ' ';
                switch(stockPrice.charAt(j)) {
        			case 'R':
        				graph[start--][j] = '/';
                        break;
        			case 'F':
        				graph[++start][j] = '\\';
                        break;
        			case 'C':
        				graph[start][j] = '_';
                }
    		}
    		for(int j = 0; j < max - min + 1; ++j) {
    			len = graph[j].length - 1;
    			while(graph[j][len] == ' ')
    		    	--len;
    			output.append("| ").append(new String(graph[j], 0, len + 1)).append('\n');
    		}
    		output.append('+');
    		len = stockPrice.length() + 2;
    		while(len-- > 0)
    			output.append('-');
    		output.append("\n\n");
    	}
	    System.out.print(output);
	}
}
