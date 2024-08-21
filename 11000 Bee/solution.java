// #解法一(正規演算法)
import java.io.*;

public class Main {
    static long[] F = new long[45];
    static int[] M = new int[45];
	public static void main (String[] args) throws IOException {
		F[0] = 1;
		for(int i = 1; i < 45; ++i) {
            F[i] = M[i - 1] + 1;
            M[i] = (int)F[i - 1] + M[i - 1];
        }
		StreamTokenizer st = new StreamTokenizer(System.in);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != -1)
		    output.append(M[N]).append(' ').append(F[N] + M[N]).append('\n');
		System.out.print(output);
	}
}

// #解法二(捷徑)
import java.io.*;

public class Main {
    static long[] F = {
        1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 
        89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 
        10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 
        1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 
        165580141, 267914296, 433494437, 701408733, 1134903170
    };
    static int[] M = {
        0, 1, 2, 4, 7, 12, 20, 33, 54, 88, 
        143, 232, 376, 609, 986, 1596, 2583, 4180, 6764, 10945, 
        17710, 28656, 46367, 75024, 121392, 196417, 317810, 514228, 832039, 1346268, 
        2178308, 3524577, 5702886, 9227464, 14930351, 24157816, 39088168, 63245985, 102334154, 165580140, 
        267914295, 433494436, 701408732, 1134903169, 1836311902
    };
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != -1)
		    output.append(M[N]).append(' ').append(F[N] + M[N]).append('\n');
		System.out.print(output);
	}
}
