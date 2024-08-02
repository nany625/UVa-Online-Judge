// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int L = (int)st.nval, swap = 0;
            int[] a = new int[L];
	        for(int i = 0; i < L; ++i) {
                st.nextToken();
	            a[i] = (int)st.nval;
                for(int j = 0; j < i; ++j) {
                    if(a[j] > a[i])
                        ++swap;
                }
	        }
	        output.append("Optimal train swapping takes " + swap + " swaps.\n");
		}
        System.out.print(output);
	}
}

// #解法二
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int L = (int)st.nval;
            int[] a = new int[L], reg = new int[L], swap = new int[1];
	        for(int i = 0; i < L; ++i) {
                st.nextToken();
	            a[i] = (int)st.nval;
	        }
	        MergeSort(a, reg, 0, L - 1, swap);
	        output.append("Optimal train swapping takes " + swap[0] + " swaps.\n");
		}
        System.out.print(output);
	}
	
	static void MergeSort(int[] array, int[] reg, int left, int right, int[] swap) {
		if(left < right) {
			int mid = left + (right - left) / 2;
			MergeSort(array, reg, left, mid, swap);
			MergeSort(array, reg, mid + 1, right, swap);
			int leftPointer = left, rightPointer = mid + 1;
    		for(int i = left; i <= right; i++) {
    			if(leftPointer > mid) {
    				reg[i] = array[rightPointer++];
    				swap[0] += mid - leftPointer + 1;
    			} else if(rightPointer > right)
    				reg[i] = array[leftPointer++];
    			else if(array[leftPointer] <= array[rightPointer])
    				reg[i] = array[leftPointer++];
    			else {
    				reg[i] = array[rightPointer++];
    				swap[0] += mid - leftPointer + 1;
    			}
    		}
    		System.arraycopy(reg, left, array, left, right - left + 1);
		}
	}
}
