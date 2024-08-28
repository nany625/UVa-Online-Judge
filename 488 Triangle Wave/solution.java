import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int amplitude = (int)st.nval;
            st.nextToken();
            int frequency = (int)st.nval;
            boolean firstWave = true;
            while(frequency-- > 0) {
    			if(!firstWave)
    				output.append('\n');
    			for(int i = 1; i <= amplitude; ++i) {
    				for(int j = 1; j <= i; ++j)
    					output.append(i);
    				output.append('\n');
    			}
    			for(int i = amplitude - 1; i >= 1; --i) {
    				for(int j = 1; j <= i; ++j)
    					output.append(i);
    				output.append('\n');
    			}
    			firstWave = false;
    		}
    		if(cases > 0)
                output.append('\n');
        }
        System.out.print(output);
	}
}
