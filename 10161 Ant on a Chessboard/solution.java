import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int circle = (int)Math.ceil(Math.sqrt(N)), corner = 1 + circle * (circle - 1);
            if(circle % 2 == 1) {
                if(N < corner) 
                    output.append(String.format("%d %d\n", circle, circle - (corner - N)));
                else
                    output.append(String.format("%d %d\n", circle - (N - corner), circle));
            } else {
    			if(N < corner)
                    output.append(String.format("%d %d\n", circle - (corner - N), circle));
                else
                    output.append(String.format("%d %d\n", circle, circle - (N - corner)));
    		}
        }
        System.out.print(output);
	}
}
