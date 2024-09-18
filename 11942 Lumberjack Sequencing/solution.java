import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        short[] lumberjacks = new short[10];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        output.append("Lumberjacks:\n");
        while(N-- > 0) {
            for(int i = 0; i < 10; ++i) {
                st.nextToken();
	            lumberjacks[i] = (short)st.nval;
            }
            boolean ordered = true;
            for(int i = 0; i < 8 && ordered; ++i)
	            ordered = lumberjacks[i] > lumberjacks[i + 1] == lumberjacks[i + 1] > lumberjacks[i + 2];
    	    output.append(ordered ? "Ordered\n" : "Unordered\n");
        }
        System.out.print(output);
	}
}
