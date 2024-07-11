import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		br.readLine();
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
            if(i > 1)
                output.append("\n");
            output.append("Case #" + i + ":\n");
            String message;
            while((message = br.readLine()) != null && !message.isEmpty()) {
                String[] tokens = message.split("\\s+");
                int count = 0;
                for(String s : tokens) {
                    if(s.length() > count)
                        output.append(s.charAt(count++));
                }
                output.append("\n");
            }
        }
		System.out.print(output);
	}
}
