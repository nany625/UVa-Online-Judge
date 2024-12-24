import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int a = (int)st.nval;
		    st.nextToken();
		    int c = (int)st.nval;
		    st.nextToken();
		    int m = (int)st.nval;
		    st.nextToken();
		    int x = (int)st.nval;
		    st.nextToken();
		    int q = (int)st.nval;
		    st.nextToken();
		    int n = (int)st.nval;
		    int[][] indices = new int[2][m];
		    int pos = 0;
		    do {
		    	indices[0][x] = ++pos;
		    	x = (a * x + c) % m;
		    } while(indices[0][x] == 0);
		    int temp = indices[0][x] - 1, cycle = pos - temp;
	        n -= temp;
	        for(int i = 0, j = 0; j < pos; ++i) {
	            if(indices[0][i] == 0)
	                continue;
	            if(indices[0][i] <= temp)
	                indices[1][j] = 1;
	            else
	                indices[1][j] = n / cycle + (indices[0][i] - temp - 1 < n % cycle ? 1 : 0);
	            indices[0][j++] = i;
	        }
	        for(int i = 1; i < pos; ++i)
	            indices[1][i] += indices[1][i - 1];
	        while(q-- > 0) {
	        	st.nextToken();
	        	output.append(indices[0][binarySearch(indices[1], pos, (int)st.nval)]).append('\n');
	        }
		}
		System.out.print(output);
	}
	
	static int binarySearch(int[] array, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
