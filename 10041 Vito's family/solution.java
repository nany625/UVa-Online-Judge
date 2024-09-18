// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int r = (int)st.nval;
            short[] s = new short[r];
            for(int i = 0; i < r; ++i) {
                st.nextToken();
                s[i] = (short)st.nval;
            }
            int median = (r - 1) >> 1;
            DualPivotQuickSelect(s, 0, r - 1, median);
            long d = 0;
            for(int i = 0; i < r; ++i)
                d += Math.abs(s[median] - s[i]);
            output.append(d).append('\n');
        }
        System.out.print(output);
	}
	
	static void swap(short[] array, int i, int j) {
	    short temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	}
	
	static int[] DualPivotPartition(short[] array, int left, int right) {
		if(array[left] > array[right])
			swap(array, left, right);
		int low = left + 1, high = right - 1;
		short pivot1 = array[left], pivot2 = array[right];
		for(int i = low; i <= high; i++) {
			if(array[i] < pivot1)
				swap(array, low++, i);
			else if(array[i] > pivot2)
				swap(array, high--, i--);
		}
		swap(array, --low, left);
		swap(array, ++high, right);
		return new int[]{low, high};
	}
	
	static void DualPivotQuickSelect(short[] array, int left, int right, int median) {
		if(left < right) {
			int[] partitionIndices = DualPivotPartition(array, left, right);
			if(median == partitionIndices[0] || median == partitionIndices[1])
			    return;
			if(median < partitionIndices[0])
			    DualPivotQuickSelect(array, left, partitionIndices[0] - 1, median);
			else if(median > partitionIndices[1])
			    DualPivotQuickSelect(array, partitionIndices[1] + 1, right, median);
			else
			    DualPivotQuickSelect(array, partitionIndices[0] + 1, partitionIndices[1] - 1, median);
		}
	}
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int r = (int)st.nval;
            short[] s = new short[r];
            for(int i = 0; i < r; ++i) {
                st.nextToken();
                s[i] = (short)st.nval;
            }
            Arrays.sort(s);
            int median = (r - 1) >> 1;
            long d = 0;
            for(int i = 0; i < r; ++i)
                d += Math.abs(s[median] - s[i]);
            output.append(d).append('\n');
        }
        System.out.print(output);
	}
}
