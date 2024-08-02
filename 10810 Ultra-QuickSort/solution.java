import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    int[] array = new int[n], reg = new int[n];
		    long[] swap = new long[1];
		    for(int i = 0; i < n; ++i) {
		        st.nextToken();
		        array[i] = (int)st.nval;
		    }
		    MergeSort(array, reg, 0, n - 1, swap);
		    output.append(swap[0] + "\n");
		}
		System.out.print(output);
	}
	
	static void MergeSort(int[] array, int[] reg, int left, int right, long[] swap) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            MergeSort(array, reg, left, mid, swap);
            MergeSort(array, reg, mid + 1, right, swap);
            int leftPointer = left, rightPointer = mid + 1;
            for(int i = left; i <= right; ++i) {
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
