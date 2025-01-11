import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_WORD) {
			String name = st.sval;
			int ST = 1;
			while(ST <= 10000) {
				StringBuilder num = new StringBuilder();
				for(int i = 0; i < name.length(); ++i)
					num.append(name.charAt(i) - 'A' + ST);
				int[][] YuanFen = new int[num.length() - 2][num.length()];
				for(int i = 0; i < num.length(); ++i)
				    YuanFen[0][i] = num.charAt(i) - '0';
				for(int i = 1; i < num.length() - 2; ++i) {
				    for(int j = 0; j < num.length() - i; ++j)
				        YuanFen[i][j] = (YuanFen[i - 1][j] + YuanFen[i - 1][j + 1]) % 10;
				}
				if(YuanFen[num.length() - 3][0] == 1 && YuanFen[num.length() - 3][1] == 0 && YuanFen[num.length() - 3][2] == 0)
					break;
				++ST;
			}
			if(ST <= 10000)
				output.append(ST).append('\n');
			else
				output.append(":(\n");
		}
		System.out.print(output);
	}
}
