import java.io.*;
import java.util.*;

public class Main {
    static int[] primes = new int[4792];
    static int count = 1;
	public static void main(String[] args) {
	    try {
	        primes[0] = 2;
    		for(int i = 3; count < primes.length; i += 2) {
    		    if(isPrime(i))
    		        primes[count++] = i;
    		}
	        StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                int L = (int)st.nval;
                st.nextToken();
                int U = (int)st.nval, C1 = 0, C2 = 0, D1 = 0, D2 = 0;
    		    ArrayList<Integer> primeList = new ArrayList<>();
    		    if(L == 1) {
    		        primeList.add(1);
    		        primeList.add(2);
    		        C1 = D1 = 1;
    		        C2 = D2 = 2;
    		        L = 3;
    		    } else if(L == 2) {
    		        primeList.add(2);
    		        L = 3;
    		    } else
    		        L += (L + 1) % 2;
    		    for(int i = L; i <= U; i += 2) {
                    if(i <= primes[primes.length - 1]) {
                        if(Arrays.binarySearch(primes, i) >= 0)
                            primeList.add(i);
                    } else {
                        if(isPrime(i))
                            primeList.add(i);
                    }
                    if(primeList.size() == 2) {
                        C1 = D1 = primeList.get(0);
                        C2 = D2 = primeList.get(1);
                    } else if(primeList.size() > 2) {
                        if(C2 - C1 > primeList.get(primeList.size() - 1) - primeList.get(primeList.size() - 2)) {
                            C1 = primeList.get(primeList.size() - 2);
                            C2 = primeList.get(primeList.size() - 1);
                        }
                        if(D2 - D1 < primeList.get(primeList.size() - 1) - primeList.get(primeList.size() - 2)) {
                            D1 = primeList.get(primeList.size() - 2);
                            D2 = primeList.get(primeList.size() - 1);
                        }
                    }
                }
                if(primeList.size() < 2)
        		    System.out.println("There are no adjacent primes.");
        		else
        		    System.out.println(C1 + "," + C2 + " are closest, " + D1 + "," + D2 + " are most distant.");
            }
	    } catch(IOException e) {}
	}
	
	static boolean isPrime(int n) {
	    int limit = (int)Math.sqrt(n);
    	for(int i = 0; i < count && primes[i] <= limit; ++i) {
    		if(n % primes[i] == 0)
    			return false;
    	}
    	return true;
	}
}
