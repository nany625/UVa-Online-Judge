import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            st.nextToken();
            int d = (int)st.nval;
            st.nextToken();
            int r = (int)st.nval;
            if(n == 0 && d == 0 && r == 0)
                break;
            short[] morning = new short[n], evening = new short[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                morning[i] = (short)st.nval;
            }
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                evening[i] = (short)st.nval;
            }
            Arrays.sort(morning);
            Arrays.sort(evening);
            int pay = 0;
            for(int i = 0; i < n; ++i) {
                short route = (short)(morning[i] + evening[n - 1 - i]);
                pay += (route > d) ? (route - d) * r : 0;
            }
            output.append(pay + "\n");
        }
        System.out.print(output);
	}
}
