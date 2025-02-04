import java.io.*;

public class Main {
    static int[] ans = new int[2];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		int[] heights = new int[N];
		for(int i = 0; i < N; ++i) {
		    st.nextToken();
		    heights[i] = (int)st.nval;
		}
		st.nextToken();
		int Q = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(Q-- > 0) {
		    st.nextToken();
    		int height = (int)st.nval;
    		binarySearch(heights, height);
    		if(ans[0] == -1)
                output.append('X');
            else
                output.append(ans[0]);
            if(ans[1] == -1)
                output.append(" X\n");
            else
                output.append(' ').append(ans[1]).append('\n');
		}
		System.out.print(output);
	}
	
	static void binarySearch(int[] array, int key) {
        int left = 0, right = array.length - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(array[mid] == key) {
                left = mid - 1;
                while(left >= 0 && array[left] == key)
                    --left;
                ans[0] = left == -1 ? -1 : array[left];
                right = mid + 1;
                while(right < array.length && array[right] == key)
                    ++right;
                ans[1] = right == array.length ? -1 : array[right];
                return;
            }
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        ans[0] = left == 0 ? -1 : array[left - 1];
        ans[1] = left == array.length ? -1 : array[left];
    }
}
