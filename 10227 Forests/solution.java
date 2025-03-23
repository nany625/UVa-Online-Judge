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
            st.nextToken();
            int P = (int)st.nval;
            st.nextToken();
            int T = (int)st.nval;
            int[][] hear = new int[P][T];
            String s;
            while((s = br.readLine()) != null && !s.isEmpty()) {
                String[] tokens = s.split("\\s+");
                hear[Integer.parseInt(tokens[0]) - 1][Integer.parseInt(tokens[1]) - 1] = 1;
            }
            HashMap<String, Boolean> opinions = new HashMap<>();
            for(int[] array : hear) {
                String opinion = "";
                for(Integer i : array)
                    opinion += i;
                if(!opinions.containsKey(opinion))
                    opinions.put(opinion, true);
            }
            output.append(opinions.size()).append('\n');
            if(cases > 0)
                output.append('\n');
        }
        System.out.print(output);
    }
}
