import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(N-- > 0) {
    	    String expression = br.readLine();
    	    long max = 1, prev = 0;
            int next = 0, len = expression.length();
            boolean add = false;
            for(int i = 0; i < len; ++i) {
                switch(expression.charAt(i)) {
                    case '+':
                        add = true;
                        prev += next;
                        next = 0;
                        break;
                    case '*':
                        add = false;
                        max *= (prev + next);
                        prev = 0;
                        next = 0;
                        break;
                    default:
                        if(!add)
                            prev = 10 * prev + expression.charAt(i) - '0';
                        else
                            next = 10 * next + expression.charAt(i) - '0';
                }
            }
            max *= (prev + next);
            long min = 0;
            prev = 0;
            next = 1;
            add = true;
            for(int i = 0; i < len; ++i) {
                switch(expression.charAt(i)) {
                    case '+':
                        add = true;
                        min += prev * next;
                        prev = 0;
                        next = 1;
                        break;
                    case '*':
                        add = false;
                        prev *= next;
                        next = 0;
                        break;
                    default:
                        if(add)
                            prev = 10 * prev + expression.charAt(i) - '0';
                        else
                            next = 10 * next + expression.charAt(i) - '0';
                }
            }
            min += prev * next;
            output.append("The maximum and minimum are " + max + " and " + min + ".\n");
    	}
        System.out.print(output);
	}
}
