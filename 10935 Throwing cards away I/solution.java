import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
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
		            output.append(" " + cards.removeFirst() + ",");
		            cards.add(cards.removeFirst());
		        }
		        output.append(" " + cards.get(0) + "\nRemaining card: " + cards.get(1) + "\n");
		    }
		}
		System.out.print(output);
	}
}
