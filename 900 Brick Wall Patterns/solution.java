import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    long[] Fib = {
            1L, 2L, 3L, 5L, 8L, 13L, 21L, 34L, 55L, 89L,
            144L, 233L, 377L, 610L, 987L, 1597L, 2584L, 4181L, 6765L, 10946L,
            17711L, 28657L, 46368L, 75025L, 121393L, 196418L, 317811L, 514229L, 832040L, 1346269L,
            2178309L, 3524578L, 5702887L, 9227465L, 14930352L, 24157817L, 39088169L, 63245986L, 102334155L, 165580141L,
            267914296L, 433494437L, 701408733L, 1134903170L, 1836311903L, 2971215073L, 4807526976L, 7778742049L, 12586269025L, 20365011074L
    	};
        StreamTokenizer st = new StreamTokenizer(System.in);
        int length;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (length = (int)st.nval) != 0)
            output.append(Fib[length - 1] + "\n");
	    System.out.print(output);
	}
}
