import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        double V, Vo;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (V = st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (Vo = st.nval) != 0) {
            double discs = V / 2 / Vo;
    	    if(discs - (int)discs == 0.5)
    	        output.append("0\n");
    	    else if(discs - (int)discs < 0.5)
           		output.append((int)discs).append('\n');
           	else
           		output.append((int)discs + 1).append('\n');
        }
        System.out.print(output);
	}
}
