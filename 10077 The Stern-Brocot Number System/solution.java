import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
			int m = (int)st.nval;
			st.nextToken();
			int n = (int)st.nval;
			if(m == 1 && n == 1)
			    break;
		    int[][] add = {{0, 1}, {1, 0}};
		    int a = 1, b = 1;
		    while(a != m || b != n) {
		        if(a * n > b * m) {
		            output.append('L');
		            a = add[0][0] + (add[0][1] = a);
		            b = add[1][0] + (add[1][1] = b);
		        } else {
		            output.append('R');
		            a = (add[0][0] = a) + add[0][1];
                    b = (add[1][0] = b) + add[1][1];
		        }
		    }
		    output.append('\n');
		}
		System.out.print(output);
	}
}
