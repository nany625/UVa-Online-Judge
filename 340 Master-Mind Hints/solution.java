import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StreamTokenizer st = new StreamTokenizer(br);
            int games = 0, N;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
                System.out.println("Game " + (++games) + ":");
    			char[] secretCode = new char[N];
    			for(int i = 0; i < N; ++i) {
    				secretCode[i] = (char)br.read();
    				br.read();
    			}
    			char[] guess = new char[N];
    			boolean lastGuess;
    			do {
    				lastGuess = true;
    				for(int i = 0; i < N; ++i) {
    					guess[i] = (char)br.read();
    					br.read();
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
    					System.out.println("    (" + a + "," + b + ")");
    				}
    			} while(!lastGuess);
            }
        } catch(IOException e) {};
    }
}
