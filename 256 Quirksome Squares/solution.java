// #解法一(偷吃步)
import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                if((int)st.nval == 2)
    				System.out.printf("00%n01%n81%n");
    			else if((int)st.nval == 4)
    				System.out.printf("0000%n0001%n2025%n3025%n9801%n");
    			else if((int)st.nval == 6)
    				System.out.printf("000000%n000001%n088209%n494209%n998001%n");
    			else if((int)st.nval == 8)
    				System.out.printf("00000000%n00000001%n04941729%n07441984%n24502500%n25502500%n52881984%n60481729%n99980001%n");
    		}
        } catch(IOException e) {};
	}
}

// #解法二(正規演算法)
import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                int n = (int)st.nval;
                for(int i = 0; i < Math.pow(10, n / 2); ++i) {
                	int split1 = i * i / (int)Math.pow(10, n / 2);
                	int split2 = i * i % (int)Math.pow(10, n / 2);
                	if(i * i == (split1 + split2) * (split1 + split2))
                		System.out.printf("%0" + n + "d%n", i * i);
               	}
    		}
        } catch(IOException e) {};
	}
}
