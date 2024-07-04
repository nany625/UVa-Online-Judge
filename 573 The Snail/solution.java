import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    double H;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (H = st.nval) != 0) {
    	    st.nextToken();
    	    double U = st.nval;
    	    st.nextToken();
    	    double D = st.nval;
    	    st.nextToken();
    	    double F = st.nval;
    	    int day = 0;
    	    double curr = 0, lost = U * F / 100;
    	    do {
    	        ++day;
    	        curr += U;
    	        if(curr > H)
    	            break;
    	        curr -= D;
    	        U = U >= lost ? U - lost : 0;
    	    } while(curr >= 0);
    	    output.append((curr > H ? "success" : "failure") + " on day " + day + "\n");
		}
        System.out.print(output);
	}
}
