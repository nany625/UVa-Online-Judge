import java.io.*;

public class Main {
    static int[] cp = {
        113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 
        971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 
        11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 
        193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 
        993319, 999331
    };
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int i;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (i = (int)st.nval) != -1) {
            st.nextToken();
            int j = (int)st.nval;
            int posI = binarySearch(i), posJ = binarySearch(j);
	   	    int cpCount =  (posJ - posI) + (posJ < 42 && cp[posJ] == j ? 1 : 0);
            if(cpCount == 0)
        		output.append("No Circular Primes.\n");
        	else
        		output.append(cpCount + " Circular Prime" + (cpCount > 1 ? "s.\n" : ".\n"));
        }
	    System.out.print(output);
	}
	
	static int binarySearch(int key) {
	    int left = 0, right = 41;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(cp[mid] == key)
				return mid;
			if(cp[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
}
