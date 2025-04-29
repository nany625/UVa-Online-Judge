import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= t; ++i) {
            String team = br.readLine();
            String judge = br.readLine();
            if(team.equals(judge))
                output.append("Case ").append(i).append(": Yes\n");
            else {
                String[] tokens = team.split("\\s+");
                StringBuilder teamSb = new StringBuilder();
                for(String s : tokens)
                    teamSb.append(s);
                tokens = judge.split("\\s+");
                StringBuilder judgeSb = new StringBuilder();
                for(String s : tokens)
                    judgeSb.append(s);
                if(teamSb.toString().equals(judgeSb.toString()))
                    output.append("Case ").append(i).append(": Output Format Error\n");
                else
                    output.append("Case ").append(i).append(": Wrong Answer\n");
            }
    	}
        System.out.print(output);
	}
}
