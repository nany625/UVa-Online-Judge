import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int G;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (G = (int)st.nval) != 0) {
            String s = br.readLine();
            for(int i = 0; i < G; ++i) {
                for(int j = (i + 1) * s.length() / G - 1; j >= i * s.length() / G; --j)
                    output.append(s.charAt(j));
            }
    		output.append('\n');
        }
        System.out.print(output);
	}
}
