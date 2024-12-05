// #解法一(正規演算法)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval, limit = (int)Math.pow(10, n >> 1);
            for(int i = 0; i < limit; ++i) {
            	int split1 = i * i / limit, split2 = i * i % limit;
            	if(i * i == (split1 + split2) * (split1 + split2))
            		output.append(String.format("%0" + n + "d\n", i * i));
           	}
		}
        System.out.print(output);
	}
}

// #解法二(捷徑)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            switch((int)st.nval) {
                case 2:
    			    output.append("00\n01\n81\n");
                    break;
			    case 4:
    			    output.append("0000\n0001\n2025\n3025\n9801\n");
                    break;
			    case 6:
    			    output.append("000000\n000001\n088209\n494209\n998001\n");
                    break;
			    case 8:
    			    output.append("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
            }
		}
        System.out.print(output);
	}
}
