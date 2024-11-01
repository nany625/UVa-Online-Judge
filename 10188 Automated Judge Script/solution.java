import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int x = 0, n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            StringBuilder solution = new StringBuilder();
            while(n-- > 0)
                solution.append(br.readLine()).append('\n');
            st.nextToken();
            int m = (int)st.nval;
            StringBuilder teamOutput = new StringBuilder();
            while(m-- > 0)
                teamOutput.append(br.readLine()).append('\n');
            if(solution.toString().contentEquals(teamOutput))
                output.append("Run #").append(++x).append(": Accepted\n");
            else {
                int i = 0, j = 0;
                while(i < solution.length() && j < teamOutput.length()) {
    		        while(i < solution.length() && !Character.isDigit(solution.charAt(i)))
    		            ++i;
    		        while(j < teamOutput.length() && !Character.isDigit(teamOutput.charAt(j)))
    		            ++j;
    		        if(i < solution.length() && j < teamOutput.length()) {
    		            if(solution.charAt(i) != teamOutput.charAt(j))
    		                break;
    		            ++i;
    		            ++j;
    		        } else
                        break;
    		    }
    		    if(i == solution.length() && j == teamOutput.length())
    		        output.append("Run #").append(++x).append(": Presentation Error\n");
    		    else
    		        output.append("Run #").append(++x).append(": Wrong Answer\n");
            }
        }
        System.out.print(output);
	}
}
