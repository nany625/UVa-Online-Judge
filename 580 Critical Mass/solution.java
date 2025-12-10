import java.io.*;

public class Main {
    static int[] ans = {
    	0, 0, 0, 1, 3, 8, 20, 47, 107, 238,
    	520, 1121, 2391, 5056, 10616, 22159, 46023, 95182, 196132, 402873,
    	825259, 1686408, 3438828, 6999071, 14221459, 28853662, 58462800, 118315137, 239186031, 483072832,
    	974791728
    };
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int size;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (size = (int)st.nval) != 0)
            output.append(ans[size]).append('\n');
        System.out.print(output);
	}
}
