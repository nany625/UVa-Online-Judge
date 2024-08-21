import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String num;
		StringBuilder output = new StringBuilder();
		while((num = br.readLine()) != null && num.charAt(0) != '-') {
		    if(num.length() > 2 && num.charAt(1) == 'x')
		        output.append(Integer.parseInt(num.substring(2), 16)).append('\n');
		    else
		        output.append(String.format("0x%X\n", Integer.parseInt(num)));
		}
		System.out.print(output);
	}
}
