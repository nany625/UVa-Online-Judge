import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();
        String line;
        boolean firstCase = true;
        while((line = br.readLine()) != null) {
            if(!firstCase)
                output.append("\n");
            int len = line.length();
            for(int i = 0; i < len; ++i)
                output.append((char)(line.charAt(i) - 7));
            firstCase = false;
        }
        System.out.print(output);
	}
}
