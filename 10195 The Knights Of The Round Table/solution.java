import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
			double a = st.nval;
			st.nextToken();
			double b = st.nval;
			st.nextToken();
			double c = st.nval;
			if(a + b + c == 0)
			    output.append("The radius of the round table is: 0.000\n");
			else {
			    double s = (a + b + c) / 2;
                double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
                output.append(String.format("The radius of the round table is: %.3f\n", area * 2 / (a + b + c)));
			}
		}
		System.out.print(output);
	}
}
