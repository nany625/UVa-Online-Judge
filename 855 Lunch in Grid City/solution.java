// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0)  {
    	    st.nextToken();
            int S = (int)st.nval;
            st.nextToken();
            int A = (int)st.nval;
            st.nextToken();
            int F = (int)st.nval;
            short[] streetLocations = new short[F], avenueLocations = new short[F];
            for(int i = 0; i < F; ++i) {
                st.nextToken();
    			streetLocations[i] = (short)st.nval;
    			st.nextToken();
    			avenueLocations[i] = (short)st.nval;
    		}
    		Arrays.sort(streetLocations);
    		Arrays.sort(avenueLocations);
    		int median = (F - 1) / 2;
    		output.append("(Street: " + streetLocations[median] + ", Avenue: " + avenueLocations[median] + ")\n");
        }
	    System.out.print(output);
	}
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0)  {
    	    st.nextToken();
            int S = (int)st.nval;
            st.nextToken();
            int A = (int)st.nval;
            st.nextToken();
            int F = (int)st.nval;
            short[] streetLocations = new short[F], avenueLocations = new short[F];
            for(int i = 0; i < F; ++i) {
                st.nextToken();
    			streetLocations[i] = (short)st.nval;
    			st.nextToken();
    			avenueLocations[i] = (short)st.nval;
    		}
    		int median = (F - 1) / 2;
    		DualPivotQuickSelect(streetLocations, 0, F - 1, median);
    		DualPivotQuickSelect(avenueLocations, 0, F - 1, median);
    		output.append("(Street: " + streetLocations[median] + ", Avenue: " + avenueLocations[median] + ")\n");
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
    	int low = left + 1, high = right - 1, pivot1 = array[left], pivot2 = array[right];
    	for(int i = low; i <= high; ++i) {
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
