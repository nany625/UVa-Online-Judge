import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    char[][] fac = new char[1000][];
    	fac[0] = new char[1];
    	fac[0][0] = '1';
		short[] digits = new short[1000];
		digits[0] = 1;
    	for(int i = 1; i < 1000; ++i) {
    	    int num = i + 1;
    	    while(num % 10 == 0)
    	        num /= 10;
    	    String temp = "" + num;
    	    int len = temp.length();
    	    fac[i] = new char[digits[i - 1] + len];
    	    Arrays.fill(fac[i], '0');
    	    for(int j = len - 1; j >= 0; --j) {
    	        for(int k = digits[i - 1] - 1; k >= 0; --k) {
    	            fac[i][j + k] += ((fac[i - 1][k] - '0') * (temp.charAt(j) - '0') + fac[i][j + k + 1] - '0') / 10;
    	            fac[i][j + k + 1] = (char)(((fac[i - 1][k] - '0') * (temp.charAt(j) - '0') + fac[i][j + k + 1] - '0') % 10 + '0');
    	        }
    	    }
    	    int j = 0;
    	    while(fac[i][j] == '0')
    	        ++j;
    	    digits[i] = (short)(digits[i - 1] + len - j);
    	    System.arraycopy(fac[i], j, fac[i], 0, digits[i]);
    	    while(fac[i][digits[i] - 1] == '0')
    	        --digits[i];
    	}
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int n = (int)st.nval, sumOfDigits = 0;
    	    for(int i = 0; i < digits[n - 1]; ++i)
    			sumOfDigits += fac[n - 1][i] - '0';
    		output.append(sumOfDigits + "\n");
    	}
	    System.out.print(output);
	}
}
