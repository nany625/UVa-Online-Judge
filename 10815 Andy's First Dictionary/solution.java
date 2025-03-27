import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		TreeSet<String> dict = new TreeSet<>();
		StringBuilder temp = new StringBuilder();
		int c;
		while((c = br.read()) != -1) {
		    char ch = (char)c;
		    if(Character.isLetter(ch))
				temp.append(Character.toLowerCase(ch));
			else {
			    if(temp.length() > 0)
			        dict.add(temp.toString());
			    temp.setLength(0);
			}
		}
		if(temp.length() > 0)
		    dict.add(temp.toString());
		StringBuilder output = new StringBuilder();
		for(String s : dict)
			output.append(s).append('\n');
		System.out.print(output);
	}
}

