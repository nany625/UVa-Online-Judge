import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
		    int[] P = new int[N], reg = new int[N];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        P[i] = (int)st.nval;
		    }
		    long[] swap = new long[1];
		    MergeSort(P, reg, 0, N - 1, swap);
		    output.append((swap[0] & 1) == 1 ? "Marcelo\n" : "Carlos\n");
		}
		System.out.print(output);
	}
	
	static void MergeSort(int[] P, int[] reg, int left, int right, long[] swap) {
        if(left < right) {
            int mid = left + ((right - left) >> 1);
            MergeSort(P, reg, left, mid, swap);
            MergeSort(P, reg, mid + 1, right, swap);
            int leftPointer = left, rightPointer = mid + 1;
            for(int i = left; i <= right; ++i) {
                if(leftPointer > mid) {
                    reg[i] = P[rightPointer++];
                    swap[0] += mid - leftPointer + 1;
                } else if(rightPointer > right)
                    reg[i] = P[leftPointer++];
                else if(P[leftPointer] <= P[rightPointer])
                    reg[i] = P[leftPointer++];
                else {
                    reg[i] = P[rightPointer++];
                    swap[0] += mid - leftPointer + 1;
                }
            }
            System.arraycopy(reg, left, P, left, right - left + 1);
        }
    }
}
