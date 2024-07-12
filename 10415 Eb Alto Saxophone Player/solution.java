import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(t-- > 0) {
		    String notes = br.readLine();
		    int[] press = new int[10];
		    String prev = "0000000000", curr = "";
		    int len = notes.length();
		    for(int i = 0; i < len; ++i) {
		        switch(notes.charAt(i)) {
                    case 'c':
    					curr = "0111001111";
    					break;
    				case 'd':
    					curr = "0111001110";
    					break;
    				case 'e':
    					curr = "0111001100";
    					break;
    				case 'f':
    					curr = "0111001000";
    					break;
    				case 'g':
    					curr = "0111000000";
    					break;
    				case 'a':
    					curr = "0110000000";
    					break;
    				case 'b':
    					curr = "0100000000";
    					break;
    				case 'C':
    					curr = "0010000000";
    					break;
    				case 'D':
    					curr = "1111001110";
    					break;
    				case 'E':
    					curr = "1111001100";
    					break;
    				case 'F':
    					curr = "1111001000";
    					break;
    				case 'G':
    					curr = "1111000000";
    					break;
    				case 'A':
    					curr = "1110000000";
    					break;
    				case 'B':
    					curr = "1100000000";
                }
                for(int j = 0; j < 10; ++j) {
                    if(j == 4 || j == 5)
                        continue;
                    press[j] += (curr.charAt(j) > prev.charAt(j) ? 1 : 0);
                }
                prev = curr;
		    }
		    for(int j = 0; j < 9; ++j)
                output.append(press[j] + " ");
            output.append(press[9] + "\n");
		}
		System.out.print(output);
	}
}
