import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            int len = line.length();
            for(int i = 0; i < len; ++i)
                output.append((char)(line.charAt(i) - 7));
            output.append("\n");
        }
        System.out.print(output);
	}
}
