import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.split("\\s+");
            long low = Long.parseLong(tokens[0]);
            long high = Long.parseLong(tokens[1]);
            if(low == 0 && high == 0)
                break;
            output.append(high / 5 - low / 5 + 1).append('\n');
        }
	    System.out.print(output);
	}
}
