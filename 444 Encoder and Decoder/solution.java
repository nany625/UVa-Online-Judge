import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String message;
        StringBuilder output = new StringBuilder();
        while((message = br.readLine()) != null) {
            if(!message.isEmpty()) {
                if(Character.isDigit(message.charAt(0))) {
                    int i = message.length() - 1;
        	        while(i >= 0) {
        	            int value = (message.charAt(i) - '0') * 10 + message.charAt(i - 1) - '0';
        	            if(value <= 12) {
        	                value = value * 10 + message.charAt(i - 2) - '0';
        	                i -= 3;
        	            } else
        	                i -= 2;
        	            output.append((char)value);
        	        }
                } else {
                    for(int i = message.length() - 1; i >= 0; --i) {
        	            int value = message.charAt(i);
        	            while(value > 0) {
            	            output.append(value % 10);
            	            value /= 10;
            	        }
        	        }
                }
            }
            output.append('\n');
        }
        System.out.print(output);
	}
}
