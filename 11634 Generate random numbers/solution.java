import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        short a;
        StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (a = (short)st.nval) != 0) {
			boolean[] table = new boolean[10000];
			int count = 0;
			do {
				table[a] = true;
				++count;
				a = (short)(a * a / 100 % 10000);
			} while(!table[a]);
			output.append(count + "\n");
		}
        System.out.print(output);
    }
}
