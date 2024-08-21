import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StreamTokenizer st = new StreamTokenizer(br);
    	int N;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
	        String[] numbers = br.readLine().split("\\s+");
	        Arrays.sort(numbers, new Comparator<String>() {
	           @Override
	           public int compare(String num1, String num2) {
	               String comb1 = "" + num1 + num2;
	               String comb2 = "" + num2 + num1;
	               return comb2.compareTo(comb1);
	           }
	        });
	        for(String s : numbers)
	            output.append(s);
	        output.append('\n');
    	}
	    System.out.print(output);
	}
}
