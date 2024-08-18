import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null && line.charAt(0) != '0') {
            if(line.charAt(0) == line.charAt(4) && line.charAt(2) == line.charAt(6))
                output.append("0\n");
            else if(line.charAt(0) == line.charAt(4) || line.charAt(2) == line.charAt(6) || Math.abs(line.charAt(4) - line.charAt(0)) == Math.abs(line.charAt(6) - line.charAt(2)))
                output.append("1\n");
            else
                output.append("2\n");
        }
        System.out.print(output);
	}
}
