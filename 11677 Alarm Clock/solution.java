import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int H1 = (int)st.nval;
            st.nextToken();
            int M1 = (int)st.nval;
            st.nextToken();
            int H2 = (int)st.nval;
            st.nextToken();
            int M2 = (int)st.nval;
            if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
                break;
            int time1 = 60 * H1 + M1, time2 = 60 * H2 + M2;
            output.append(time1 <= time2 ? time2 - time1 : time2 - time1 + 1440).append('\n');
        }
        System.out.print(output);
	}
}
