import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Short> lenMap = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        lenMap.add((short)0);
		lenMap.add((short)1);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int min = (int)st.nval;
    	    st.nextToken();
    	    int max = (int)st.nval;
    	    output.append(min).append(' ').append(max).append(' ');
    	    if(min > max) {
    	        int temp = min;
    	        min = max;
    	        max = temp;
    	    }
    	    for(int i = lenMap.size(); i <= min; ++i)
    	        Collatz(i);
    	    short maxLen = lenMap.get(min);
    	    for(int i = min + 1; i <= max; ++i) {
		        if(i >= lenMap.size())
                    Collatz(i);
                maxLen = maxLen > lenMap.get(i) ? maxLen : lenMap.get(i);
            }
            output.append(maxLen).append('\n');
		}
		System.out.print(output);
	}
	
	static void Collatz(int n) {
	    if(n % 2 == 0) {
	        lenMap.add((short)(lenMap.get(n / 2) + 1));
	        return;
	    }
	    int size = lenMap.size();
	    lenMap.add((short)1);
	    long temp = n;
	    while(temp != 1) {
	        if(temp < n) {
	            lenMap.set(size, (short)(lenMap.get(size) + lenMap.get((int)temp) - 1));
	            return;
	        }
	        temp = temp % 2 == 1 ? 3 * temp + 1 : temp / 2;
            lenMap.set(size, (short)(lenMap.get(size) + 1));
	    }
	}
}
