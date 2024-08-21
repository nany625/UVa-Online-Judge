import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int c;
		StringBuilder output = new StringBuilder();
		while((c = br.read()) != -1) {
		    char ch = (char)c;
		    if(Character.isUpperCase(ch)) {
                if(ch <= 'C')
                    output.append('2');
                else if(ch <= 'F')
                    output.append('3');
                else if(ch <= 'I')
                    output.append('4');
                else if(ch <= 'L')
                    output.append('5');
                else if(ch <= 'O')
                    output.append('6');
                else if(ch <= 'S')
                    output.append('7');
                else if(ch <= 'V')
                    output.append('8');
                else
                    output.append('9');
            } else
                output.append(ch);
		}
		System.out.print(output);
	}
}
