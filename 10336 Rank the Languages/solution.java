import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= N; ++i) {
            output.append("World #" + i + "\n");
            st.nextToken();
            int H = (int)st.nval;
            st.nextToken();
            int W = (int)st.nval;
            char[][] map = new char[H][W];
            for(int j = 0; j < H; ++j) {
                st.nextToken();
                map[j] = st.sval.toCharArray();
            }
            Rank[] ranks = new Rank[26];
            for(int j = 0; j < 26; ++j)
                ranks[j] = new Rank((char)('a' + j), 0);
            for(int j = 0; j < H; ++j) {
                for(int k = 0; k < W; ++k) {
                    if(Character.isLowerCase(map[j][k])) {
                        ++ranks[map[j][k] - 'a'].states;
                        dfs(map, j, H, k, W, map[j][k]);
                    }
                }
            }
            Arrays.sort(ranks, new Comparator<Rank>() {
                @Override
                public int compare(Rank r1, Rank r2) {
                    if(r1.states == r2.states)
                        return Character.compare(r1.language, r2.language);
                    return Integer.compare(r2.states, r1.states);
                }
            });
            for(int j = 0; j < 26 && ranks[j].states > 0; ++j)
                output.append(ranks[j].language + ": " + ranks[j].states + "\n");
    	}
        System.out.print(output);
	}
	
	static void dfs(char[][] map, int row, int rowLimit, int col, int colLimit, char language) {
        if(map[row][col] == language) {
            map[row][col] = ' ';
            if(row - 1 >= 0)
                dfs(map, row - 1, rowLimit, col, colLimit, language);
            if(col - 1 >= 0)
                dfs(map, row, rowLimit, col - 1, colLimit, language);
            if(row + 1 < rowLimit)
                dfs(map, row + 1, rowLimit, col, colLimit, language);
            if(col + 1 < colLimit)
                dfs(map, row, rowLimit, col + 1, colLimit, language);
        }
    }
}

class Rank {
    char language;
    int states;
    Rank(char language, int states) {
        this.language = language;
        this.states = states;
    }
}
