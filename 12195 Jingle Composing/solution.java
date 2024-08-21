import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String composition;
        StringBuilder output = new StringBuilder();
        while((composition = br.readLine()) != null && composition.charAt(0) != '*') {
            int count = 0, duration = 0, len = composition.length();
            for(int i = 1; i < len; ++i) {
    		    switch(composition.charAt(i)) {
    			    case 'W':
    				    duration += 64;
    				    break;
        			case 'H':
        				duration += 32;
        				break;
        			case 'Q':
        				duration += 16;
        				break;
        			case 'E':
        				duration += 8;
        				break;
        			case 'S':
        				duration += 4;
        				break;
        			case 'T':
        				duration += 2;
        				break;
        			case 'X':
        				duration += 1;
        				break;
        			case '/':
        				count += (duration == 64 ? 1 : 0);
        				duration = 0;
    		    }
    		}
    	    output.append(count).append('\n');
        }
        System.out.print(output);
	}
}
