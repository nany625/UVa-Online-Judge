// #解法一(捷徑)
public class Main {
	public static void main(String[] args) {
        System.out.println("         6         8\n" +
                           "        35        49\n" +
                           "       204       288\n" +
                           "      1189      1681\n" +
                           "      6930      9800\n" +
                           "     40391     57121\n" +
                           "    235416    332928\n" +
                           "   1372105   1940449\n" +
                           "   7997214  11309768\n" +
                           "  46611179  65918161");
	}
}

// #解法二
public class Main {
	public static void main(String[] args) {
        int count = 0;
        long n = 2;
        StringBuilder output = new StringBuilder();
        while(count < 10) {
            double k = ((-(n << 1) - 1) + Math.sqrt(((n << 1) + 1) * ((n << 1) + 1) + ((n * n - n) << 2))) / 2;
            if(k == (int)k) {
                output.append(String.format("%10d%10d\n", n, n + (int)k));
                ++count;
            }
            ++n;
        }
        System.out.print(output);
	}
}
