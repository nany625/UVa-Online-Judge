import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            output.append("Case " + (++cases) + ":\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
            while(N-- > 0) {
                String line = br.readLine();
                output.append("printf(\"");
                int len = line.length();
                for(int i = 0; i < len; ++i) {
                    if(line.charAt(i) == '"' || line.charAt(i) == '\\')
                        output.append("\\");
                    output.append(line.charAt(i));
                }
                output.append("\\n\");\n");
            }
            output.append("printf(\"\\n\");\nreturn 0;\n}\n");
        }
        System.out.print(output);
	}
}
