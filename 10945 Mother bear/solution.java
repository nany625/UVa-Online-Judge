import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null && !s.equals("DONE")) {
		    int i = 0, j = s.length() - 1;
		    while(i < j) {
		        while(i < j && !Character.isLetter(s.charAt(i)))
    		        ++i;
    		    while(i < j && !Character.isLetter(s.charAt(j)))
    		        --j;
    		    if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
    		        break;
    		    ++i;
    		    --j;
		    }
		    output.append(i >= j ? "You won't be eaten!\n" : "Uh oh..\n");
		}
		System.out.print(output);
	}
}
