import java.io.*;
import java.util.*;

public class Main {
    static short[] salary = new short[3];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            for(int j = 0; j < 3; ++j) {
                st.nextToken();
                salary[j] = (short)st.nval;
            }
            Arrays.sort(salary);
            output.append("Case ").append(i).append(": ").append(salary[1]).append('\n');
        }
        System.out.print(output);
    }
}
