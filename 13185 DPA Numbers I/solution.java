import java.io.*;

public class Main {
    static char[] table = new char[998];
	public static void main(String[] args) throws IOException {
	    for(int i = 0; i < 998; ++i)
            sumOfDivisors(i);
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
		while(t-- > 0) {
    		st.nextToken();
            int n = (int)st.nval;
    		if(table[n - 2] == '0')
    			output.append("deficient\n");
    		else if(table[n - 2] == '1')
        		output.append("perfect\n");
        	else
        		output.append("abundant\n");
    	}
        System.out.print(output);
	}
	
	static void sumOfDivisors(int n) {
	    if(table[n] == '2')
	        return;
        int sum = 1, i, num = n + 2;
        float limit = (float)Math.sqrt(num);
        for(i = 2; i < limit && sum <= num; ++i) {
            if(num % i == 0)
                sum += i + num / i;
        }
        if(i == limit)
            sum += i;
        if(sum < num)
            table[n] = '0';
        else if(sum == num)
            table[n] = '1';
        else {
            for(i = num; i <= 999; i += num)
                table[i - 2] = '2';
        }
    }
}
