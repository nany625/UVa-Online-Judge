import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int games = 0, N;
		while((N = sc.nextInt()) != 0) {
			System.out.println("Game " + (++games) + ":");
			char[] secretCode = new char[N];
			for(int i = 0; i < N; ++i)
				secretCode[i] = sc.next().charAt(0);
			char[] guess = new char[N];
			boolean lastGuess;
			do {
				lastGuess = true;
				for(int i = 0; i < N; ++i) {
					guess[i] = sc.next().charAt(0);
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
		sc.close();
    }
}
