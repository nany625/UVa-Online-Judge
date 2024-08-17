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
    	    short[] A = new short[n], reg = new short[n];
    	    for(int i = 0; i < n; ++i) {
    	        st.nextToken();
    	        A[i] = (short)st.nval;
    	    }
    		int[] sum = new int[1];
    		MergeSort(A, reg, 0, n - 1, sum);
    		output.append(sum[0] + "\n");
    	}
        System.out.print(output);
	}
	
	static void MergeSort(short[] array, short[] reg, int left, int right, int[] sum) {
		if(left < right) {
			int mid = left + (right - left) / 2;
			MergeSort(array, reg, left, mid, sum);
			MergeSort(array, reg, mid + 1, right, sum);
			int leftPointer = left, rightPointer = mid + 1;
    		for(int i = left; i <= right; ++i) {
    			if(leftPointer > mid) {
    				reg[i] = array[rightPointer++];
    				sum[0] += leftPointer - left;
    			} else if(rightPointer > right)
    				reg[i] = array[leftPointer++];
    			else if(array[leftPointer] <= array[rightPointer])
    				reg[i] = array[leftPointer++];
    			else {
    				reg[i] = array[rightPointer++];
    				sum[0] += leftPointer - left;
    			}
    		}
    		System.arraycopy(reg, left, array, left, right - left + 1);
		}
	}
}
