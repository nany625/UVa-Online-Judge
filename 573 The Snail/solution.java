import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    float H;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (H = (float)st.nval) != 0) {
    	    st.nextToken();
    	    float U = (float)st.nval;
    	    st.nextToken();
    	    float D = (float)st.nval;
    	    st.nextToken();
    	    float F = (float)st.nval;
    	    int day = 0;
    	    float curr = 0, lost = U * F / 100;
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
