import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        boolean odd = true;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            for(int i = 0; i < line.length(); ++i) {
                if(line.charAt(i) == '"' && odd) {
                    output.append("``");
                    odd = false;
                } else if(line.charAt(i) == '"' && !odd) {
                    output.append("''");
                    odd = true;
                } else
                    output.append(line.charAt(i));
            }
            output.append('\n');
        }
        System.out.print(output);
	}
}
