import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            String[] tokens = br.readLine().split(":");
            int HH = Integer.parseInt(tokens[0]), MM = Integer.parseInt(tokens[1]);
            if(HH == 0) {
                if(MM < 9)
                    output.append(String.format("00:%02d\n", MM + 1));
                else if(MM < 55)
                    output.append("00:" + 11 * (MM / 11 + 1) + "\n");
                else
                    output.append("01:01\n");
            } else if(HH < 10) {
                if(MM < 50 + HH) {
                    if(MM % 10 < HH)
                        output.append(String.format("%02d:%02d\n", HH, 10 * (MM / 10) + HH));
                    else
                        output.append(String.format("%02d:%d\n", HH, 10 * (MM / 10 + 1) + HH));
                } else {
                    if(HH < 9)
                        output.append(String.format("%02d:%02d\n", HH + 1, HH + 1));
                    else
                        output.append("10:01\n");
                }
            } else if(HH < 16) {
                if(MM < HH % 10 * 10 + HH / 10)
                    output.append(String.format("%d:%02d\n", HH, HH % 10 * 10 + HH / 10));
                else {
                    ++HH;
                    if(HH < 16)
                        output.append(HH + ":" + (HH % 10 * 10 + HH / 10) + "\n");
                    else
                        output.append("20:02\n");
                }
            } else if(HH < 20)
                output.append("20:02\n");
            else if(HH < 23) {
                if(MM < HH % 10 * 10 + HH / 10)
                    output.append(String.format("%d:%02d\n", HH, HH % 10 * 10 + HH / 10));
                else {
                    ++HH;
                    output.append(HH + ":" + (HH % 10 * 10 + HH / 10) + "\n");
                }
            } else
                output.append(MM < 32 ? "23:32\n" : "00:00\n");
        }
        System.out.print(output);
	}
}
