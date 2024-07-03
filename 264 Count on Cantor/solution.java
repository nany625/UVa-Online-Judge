import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int number = (int)st.nval;
            int i = (int)Math.ceil((-1 + Math.sqrt(1 + 8 * number)) / 2);
            int a = i + 1 - number + (i - 1) * i / 2;
            int b = number - (i - 1) * i / 2;
            if(i % 2 == 1)
                output.append(String.format("TERM %d IS %d/%d\n", number, a, b));
    		else
			    output.append(String.format("TERM %d IS %d/%d\n", number, b, a));
		}
        System.out.print(output);
	}
}
