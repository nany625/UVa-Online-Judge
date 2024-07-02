import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
    	HashMap<String, String> slogans = new HashMap<>();
    	for(int i = 0; i < N; ++i)
    	    slogans.put(br.readLine(), br.readLine());
        int Q = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();
    	while(Q-- > 0)
    		output.append(slogans.get(br.readLine()) + "\n");
        System.out.print(output);
	}
}
