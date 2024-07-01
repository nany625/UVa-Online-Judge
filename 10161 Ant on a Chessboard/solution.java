import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
            int N;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
                int circle = (int)Math.ceil(Math.sqrt(N)), corner = 1 + circle * (circle - 1);
                if(circle % 2 == 1) {
                    if(N < corner)
                        System.out.println(circle + " " + (circle - (corner - N)));
                    else
                        System.out.println((circle - (N - corner)) + " " + circle);
                } else{
        			if(N < corner)
                        System.out.println((circle - (corner - N)) + " " + circle);
                    else
                        System.out.println(circle + " " + (circle - (N - corner)));
        		}
            }
	    } catch(IOException e) {}
	}
}
