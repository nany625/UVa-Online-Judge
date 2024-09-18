// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
	        int n = (int)st.nval;
	        st.nextToken();
	        int prev = (int)st.nval;
	        int[] diff = new int[--n];
	        for(int i = 0; i < n; ++i) {
	            st.nextToken();
	            diff[i] = Math.abs(prev - (int)st.nval);
	            prev = (int)st.nval;
	        }
	        Arrays.sort(diff);
	        boolean Jolly = true;
	        for(int i = 0; i < n && Jolly; ++i) {
    	        if(diff[i] != i + 1)
    	            Jolly = false;
    	    }
    	    output.append(Jolly ? "Jolly\n" : "Not jolly\n");
	    }
        System.out.print(output);
	}
}

// #解法二
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
	        int n = (int)st.nval;
	        st.nextToken();
	        int prev = (int)st.nval;
	        int[] diff = new int[--n];
	        for(int i = 0; i < n; ++i) {
	            st.nextToken();
	            diff[i] = Math.abs(prev - (int)st.nval);
	            prev = (int)st.nval;
	        }
	        boolean[] Jolly = {true};
    	    DualPivotQuickSort(diff, 0, n - 1, Jolly);
        	output.append(Jolly[0] ? "Jolly\n" : "Not jolly\n");
    	}
        System.out.print(output);
	}
	
	static void swap(int[] array, int i, int j) {
    	int temp = array[i];
    	array[i] = array[j];
    	array[j] = temp;
    }
    
    static int[] DualPivotPartition(int[] array, int left, int right) {
		if(array[left] > array[right])
			swap(array, left, right);
		int low = left + 1, high = right - 1, pivot1 = array[left], pivot2 = array[right];
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
    
    static void DualPivotQuickSort(int[] array, int left, int right, boolean[] Jolly) {
        if(left < right) {
            int[] partitionIndices = DualPivotPartition(array, left, right);
    		if(array[partitionIndices[0]] != partitionIndices[0] + 1 || array[partitionIndices[1]] != partitionIndices[1] + 1) {
    		    Jolly[0] = false;
    		    return;
    		}
    		DualPivotQuickSort(array, left, partitionIndices[0] - 1, Jolly);
    		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1, Jolly);
    		DualPivotQuickSort(array, partitionIndices[1] + 1, right, Jolly);
        }
    }
}
