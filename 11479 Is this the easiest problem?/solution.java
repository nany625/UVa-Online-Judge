import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    output.append("Case ").append(i);
		    st.nextToken();
		    long side1 = (long)st.nval;
		    st.nextToken();
		    long side2 = (long)st.nval;
		    st.nextToken();
		    long side3 = (long)st.nval;
		    if(side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		        if(side1 == side2 && side2 == side3)
		            output.append(": Equilateral\n");
		        else if(side1 == side2 || side2 == side3 || side1 == side3)
		            output.append(": Isosceles\n");
		        else
		            output.append(": Scalene\n");
		    } else
		        output.append(": Invalid\n");
		}
		System.out.print(output);
	}
}
