import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            short[] salary = new short[3];
            for(int j = 0; j < 3; ++j) {
                st.nextToken();
                salary[j] = (short)st.nval;
            }
            Arrays.sort(salary);
            output.append("Case " + i + ": " + salary[1] + "\n");
        }
        bw.write(output.toString());
        bw.flush();
        bw.close();
    }
}
