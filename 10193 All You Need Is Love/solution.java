import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= N; ++i)
            output.append("Pair #" + i + ": " + (GCD(Integer.parseInt(br.readLine(), 2), Integer.parseInt(br.readLine(), 2)) > 1 ? "All you need is love" : "Love is not all you need") + "!\n");
        System.out.print(output);
	}
	
	static int GCD(int i, int j) {
        return j == 0 ? i : GCD(j, i % j);
    }
}
