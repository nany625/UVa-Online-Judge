// 尚未通過UVa
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int temp;
        StringBuilder output = new StringBuilder();
        while((temp = br.read()) != -1) {
            char ch = (char)temp;
            output.append(ch == '\n' ? '\n' : (char)(ch - 7));
        }
        System.out.print(output);
	}
}
