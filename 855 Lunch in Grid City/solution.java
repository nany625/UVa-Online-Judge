import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
    	    StreamTokenizer st = new StreamTokenizer(System.in);
    	    st.nextToken();
            int T = (int)st.nval;
            while(T-- > 0)  {
    		    st.nextToken();
                int S = (int)st.nval;
                st.nextToken();
                int A = (int)st.nval;
                st.nextToken();
                int F = (int)st.nval;
                short[] streetLocations = new short[F], avenueLocations = new short[F];
                for(int i = 0; i < F; ++i) {
                    st.nextToken();
    				streetLocations[i] = (short)st.nval;
    				st.nextToken();
    				avenueLocations[i] = (short)st.nval;
    			}
    			Arrays.sort(streetLocations);
    			Arrays.sort(avenueLocations);
    			int median = (F - 1) / 2;
    			System.out.println("(Street: " + streetLocations[median] + ", Avenue: " + avenueLocations[median] + ")");
            }
	    } catch(IOException e) {}
	}
}
