import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int games = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            output.append("Game " + (++games) + ":\n");
    		char[] secretCode = new char[N];
    		for(int i = 0; i < N; ++i) {
    		    st.nextToken();
    		    secretCode[i] = (char)(st.nval + '0');
    		}
    		char[] guess = new char[N];
			boolean lastGuess;
    		do {
    			lastGuess = true;
				for(int i = 0; i < N; ++i) {
				    st.nextToken();
    		        guess[i] = (char)(st.nval + '0');
					if(guess[i] != '0')
    					lastGuess = false;
    			}
				if(!lastGuess) {
    			    boolean[] check = new boolean[N];
    				int a = 0, b = 0;
					for(int i = 0; i < N; ++i) {
    					if(secretCode[i] == guess[i]) {
    						++a;
							check[i] = true;
    						guess[i] = '0';
    					}
    				}
					for(int i = 0; i < N; ++i) {
    					for(int j = 0; j < N; ++j) {
    						if(secretCode[i] == guess[j] && !check[i] && guess[j] != '0') {
    							++b;
								check[i] = true;
    							guess[j] = '0';
    							break;
    						}
    					}
					} 
    				output.append(String.format("    (%d,%d)\n", a, b));
    			}
			} while(!lastGuess);
        }
        System.out.print(output);
    }
}
