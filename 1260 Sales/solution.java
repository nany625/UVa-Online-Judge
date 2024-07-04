import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(T-- > 0) {
    	    st.nextToken();
    	    int n = (int)st.nval;
    	    short[] A = new short[n - 1];
    		int sum = 0;
    		for(int i = 0; i < n - 1; ++i) {
    		    st.nextToken();
    		    int pos = binarySearch(A, i, (short)st.nval);
    		    sum += pos;
    		    for(int j = i; j > pos; --j)
    		        A[j] = A[j - 1];
    		    A[pos] = (short)st.nval;
    		}
    		st.nextToken();
    		output.append((sum + binarySearch(A, n - 1, (short)st.nval)) + "\n");
    	}
        System.out.print(output);
	}
	
	static int binarySearch(short[] array, int size, short key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(array[mid] == key) {
                while(mid < size && array[mid] == array[mid + 1])
                    ++mid;
                return mid + 1;
            }
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
