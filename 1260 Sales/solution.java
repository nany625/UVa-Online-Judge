// #解法一
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
    			}
    			else if(rightPointer > right)
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

// #解法二
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

// #解法三
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
    	    short[] A = new short[n];
    		int sum = 0;
    		for(int i = 0; i < n; ++i) {
    		    st.nextToken();
    		    A[i] = (short)st.nval;
    		    for(int j = 0; j < i; ++j) {
    		        if(A[j] <= A[i])
					    ++sum;
    		    }
    		}
    		output.append(sum + "\n");
    	}
        System.out.print(output);
	}
}
