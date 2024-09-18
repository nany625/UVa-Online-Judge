import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    if(n == 1)
		        output.append("Discarded cards:\nRemaining card: 1\n");
		    else {
		        output.append("Discarded cards:");
		        LinkedList<Integer> cards = new LinkedList<>();
		        for(int i = 1; i <= n; ++i)
		            cards.add(i);
		        while(cards.size() > 2) {
		            output.append(' ').append(cards.removeFirst()).append(',');
		            cards.add(cards.removeFirst());
		        }
		        output.append(' ').append(cards.get(0)).append("\nRemaining card: ").append(cards.get(1)).append('\n');
		    }
		}
		System.out.print(output);
	}
}
