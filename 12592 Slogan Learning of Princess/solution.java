import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int N = (int)st.nval;
    		HashMap<String, String> slogans = new HashMap<>();
    		for(int i = 0; i < N; ++i)
    		    slogans.put(br.readLine(), br.readLine());
    		st.nextToken();
            int Q = (int)st.nval;
    		while(Q-- > 0)
    			System.out.println(slogans.get(br.readLine()));
        } catch(IOException e) {};
	}
}
