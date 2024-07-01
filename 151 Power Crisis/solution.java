// #解法一(偷吃步)
import java.util.*;

public class Main {
    static short[] ans = {
        1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 
        21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 
        42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 
        38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 
        38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 
        72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 
        67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 
        137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 
        49, 5, 22, 54, 52, 113, 15, 66
    };
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N;
        while((N = sc.nextInt()) != 0)
    		System.out.println(ans[N - 13]);
        sc.close();
    }
}

// #解法二(正規演算法)
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N;
        while((N = sc.nextInt()) != 0) {
            int i, m = 0;
            do {
                ++m;
                boolean[] regionState = new boolean[N];
                regionState[0] = true;
                int turnOff = 1, wrapCount = 0;
                i = 1;
                while(turnOff < N) {
    	            if(i == N)
    	                i = 1;
    	            if(!regionState[i])
        	            ++wrapCount;
        	        if(wrapCount == m) {
        	            ++turnOff;
        	            regionState[i] = true;
        	            wrapCount = 0;
        	        }
        	        ++i;
    	        }
            } while(i != 13);
    		System.out.println(m);
        }
        sc.close();
    }
}
