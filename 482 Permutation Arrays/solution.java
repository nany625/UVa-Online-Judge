import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
    		br.readLine();
			HashMap<Integer, String> map = new HashMap<>();
    		String[] p = br.readLine().split("\\s+");
			String[] x = br.readLine().split("\\s+");
			for(int i = 0; i < p.length; ++i)
    			map.put(Integer.parseInt(p[i]), x[i]);
			for(int i = 1; i <= p.length; ++i)
    			output.append(map.get(i)).append('\n');
    		if(cases > 0)
		        output.append('\n');
    	}
        System.out.print(output);
	}
}
