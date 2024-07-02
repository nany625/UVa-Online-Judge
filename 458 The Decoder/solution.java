import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringBuilder sb = new StringBuilder();
            int ch;
            while((ch = br.read()) != -1)
                sb.append(ch == '\n' ? '\n' : (char)(ch - 7));
            System.out.print(sb);
        } catch(IOException e) {};
	}
}
