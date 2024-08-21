import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            int[] array = new int[N], reg = new int[N], swap = new int[1];
            for(int i = 0; i < N; ++i) {
                st.nextToken();
	            array[i] = (int)st.nval;
	        }
	        MergeSort(array, reg, 0, N - 1, swap);
	        output.append("Minimum exchange operations : ").append(swap[0]).append('\n');
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
