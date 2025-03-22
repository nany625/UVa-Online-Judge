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
            ArrayList<Integer>[] hear = (ArrayList<Integer>[])new ArrayList[P];
            for(int i = 0; i < P; ++i)
                hear[i] = new ArrayList<>();
            boolean[][] used = new boolean[P][T];
            String s;
            while((s = br.readLine()) != null && !s.isEmpty()) {
                String[] tokens = s.split("\\s+");
                int i = Integer.parseInt(tokens[0]) - 1;
                int j = Integer.parseInt(tokens[1]) - 1;
                if(!used[i][j]) {
                    hear[i].add(j);
                    used[i][j] = true;
                }
            }
            HashMap<String, Boolean> opinions = new HashMap<>();
            for(ArrayList<Integer> al : hear) {
                Collections.sort(al);
                String opinion = "";
                for(Integer i : al) {
                    if(i < 10)
                        opinion += "0" + i;
                    else
                        opinion += i;
                }
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
