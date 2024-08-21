import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, String> dict = new HashMap<>();
        String line;
        StringBuilder output = new StringBuilder();
        while(!(line = br.readLine()).isEmpty()) {
            String[] tokens = line.split("\\s+");
            dict.put(tokens[1], tokens[0]);
        }
        while((line = br.readLine()) != null)
            output.append((dict.containsKey(line) ? dict.get(line) : "eh")).append('\n');
        System.out.print(output);
	}
}
