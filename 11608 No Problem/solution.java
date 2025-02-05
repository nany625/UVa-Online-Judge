import java.io.*;

public class Main {
    static int[] problems = new int[12];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int X = 0, S;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) >= 0) {
            output.append("Case ").append(++X).append(":\n");
            for(int i = 0; i < 12; ++i) {
                st.nextToken();
                problems[i] = (int)st.nval;
            }
            int total = 0;
            for(int i = 0; i < 12; ++i) {
                st.nextToken();
                int requirement = (int)st.nval;
                if(S >= total + requirement) {
                    output.append("No problem! :D\n");
                    total += requirement;
                } else
                    output.append("No problem. :(\n");
                S += problems[i];
            }
        }
        System.out.print(output);
    }
}
