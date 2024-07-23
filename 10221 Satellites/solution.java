import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    double s = st.nval;
    	    st.nextToken();
    	    double a = st.nval;
    	    st.nextToken();
    	    if(st.sval.charAt(0) == 'm')
    	        a /= 60;
    	    if(a > 180)
    	        a = 360 - a;
            output.append(String.format("%.6f %.6f\n", (6440 + s) * Math.PI * a / 180, Math.sqrt(2 * Math.pow(6440 + s, 2) * (1 - Math.cos(a * Math.PI / 180)))));
    	}
    	System.out.print(output);
	}
}
