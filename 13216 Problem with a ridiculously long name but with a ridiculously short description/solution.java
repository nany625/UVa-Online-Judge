import java.io.*;

public class Main {
    static int[] ans = {76, 16, 56, 96, 36};
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T--  > 0) {
		    String n = br.readLine();
		    if(n.charAt(0) == '0')
		        output.append("1\n");
		    else if(n.length() == 1 && n.charAt(0) == '1')
		        output.append("66\n");
		    else
		        output.append(ans[(n.charAt(n.length() - 1) - '0') % 5]).append('\n');
		}
        System.out.print(output);
	}
}
