import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String time;
		StringBuilder output = new StringBuilder();
		while((time = br.readLine()) != null) {
		    String[] tokens = time.split(":");
		    int H = Integer.parseInt(tokens[0]), M = Integer.parseInt(tokens[1]);
		    if(H == 0 && M == 0)
		        break;
		    float degree = (float)Math.abs((H %= 12) * 30 + M / 2.0 - M * 6);
		    if(degree > 180)
		        degree = 360 - degree;
		    output.append(String.format("%.3f\n", degree));
		}
		System.out.print(output);
	}
}
