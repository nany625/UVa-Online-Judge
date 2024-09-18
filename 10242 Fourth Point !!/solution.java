import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            double x1 = st.nval;
            st.nextToken();
            double y1 = st.nval;
            st.nextToken();
            double x2 = st.nval;
            st.nextToken();
            double y2 = st.nval;
            st.nextToken();
            double x3 = st.nval;
            st.nextToken();
            double y3 = st.nval;
            st.nextToken();
            double x4 = st.nval;
            st.nextToken();
            double y4 = st.nval;
            if(x1 == x3 && y1 == y3)
                output.append(String.format("%.3f %.3f\n", x2 + x4 - x1, y2 + y4 - y1));
            else if(x1 == x4 && y1 == y4)
                output.append(String.format("%.3f %.3f\n", x2 + x3 - x1, y2 + y3 - y1));
            else if(x2 == x3 && y2 == y3)
                output.append(String.format("%.3f %.3f\n", x1 + x4 - x2, y1 + y4 - y2));
            else
                output.append(String.format("%.3f %.3f\n", x1 + x3 - x2, y1 + y3 - y2));
        }
        System.out.print(output);
	}
}
