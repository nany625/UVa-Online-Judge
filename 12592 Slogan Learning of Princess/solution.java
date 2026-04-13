import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
    	Map<String, String> slogans = new HashMap<>();
    	while(N-- > 0)
    	    slogans.put(br.readLine(), br.readLine());
        st.nextToken();
        int Q = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(Q-- > 0)
    		output.append(slogans.get(br.readLine())).append('\n');
        System.out.print(output);
	}
}
