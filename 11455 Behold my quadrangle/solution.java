import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        int[] sides = new int[4];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            for(int i = 0; i < 4; ++i) {
                st.nextToken();
    			sides[i] = (int)st.nval;
            }
    		Arrays.sort(sides);
    		if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
    			output.append("square\n");
    		else if(sides[0] == sides[1] && sides[2] == sides[3])
    			output.append("rectangle\n");
    		else if(sides[0] + sides[1] + sides[2] > sides[3])
    			output.append("quadrangle\n");
    		else
    			output.append("banana\n");
        }
        System.out.print(output);
	}
}
