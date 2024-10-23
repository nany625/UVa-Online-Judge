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
            int m = (int)st.nval;
            if(n <= 1 || m <= 1) {
                output.append("Boring!\n");
                continue;
            }
            ArrayList<Integer> a = new ArrayList<>();
            a.add(n);
            while(n % m == 0)
                a.add(n /= m);
            if(n != 1)
                output.append("Boring!\n");
            else {
                int size = a.size() - 1;
                for(int i = 0; i < size; ++i)
                    output.append(a.get(i)).append(' ');
                output.append("1\n");
            }
        }
        System.out.print(output);
	}
}
