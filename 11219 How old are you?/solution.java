import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            br.readLine();
            Date curr = new Date(), birth = new Date();
            String[] tokens = br.readLine().split("/"); 
            curr.day = Integer.parseInt(tokens[0]);
            curr.month = Integer.parseInt(tokens[1]);
            curr.year = Integer.parseInt(tokens[2]);
            tokens = br.readLine().split("/"); 
            birth.day = Integer.parseInt(tokens[0]);
            birth.month = Integer.parseInt(tokens[1]);
            birth.year = Integer.parseInt(tokens[2]);
            if(birth.year * 10000 + birth.month * 100 + birth.day > curr.year * 10000 + curr.month * 100 + curr.day)
                output.append("Case #").append(i).append(": Invalid birth date\n");
            else {
                int age = curr.year - birth.year - (birth.month * 100 + birth.day > curr.month * 100 + curr.day ? 1 : 0);
                if(age > 130)
                    output.append("Case #").append(i).append(": Check birth date\n");
    			else
    				output.append("Case #").append(i).append(": ").append(age).append('\n');
            }
        }
        System.out.print(output);
	}
}

class Date {
    int year, month, day;
}
