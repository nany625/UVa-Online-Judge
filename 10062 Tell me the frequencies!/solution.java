import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while((text = br.readLine()) != null) {
            if(!firstCase)
                output.append("\n");
            ArrayList<Frequency> frequencies = new ArrayList<>();
            int len = text.length();
            for(int i = 0; i < len; ++i) {
                int pos = contain(frequencies, text.charAt(i));
                if(pos == -1)
                    frequencies.add(new Frequency(text.charAt(i), (short)1));
                else
                    ++frequencies.get(pos).count;
            }
            Collections.sort(frequencies, new Comparator<Frequency>() {
                @Override
                public int compare(Frequency f1, Frequency f2) {
                    if(f1.count != f2.count)
                        return f1.count - f2.count;
                    return f2.value - f1.value;
                }
            });
            for(Frequency f : frequencies)
                output.append((int)f.value + " " + f.count + "\n");
            firstCase = false;
        }
        System.out.print(output);
	}
	
	static int contain(ArrayList<Frequency> arrayList, char key) {
        int size = arrayList.size();
        for(int i = 0; i < size; ++i) {
            if(arrayList.get(i).value == key)
                return i;
        }
        return -1;
    }
}

class Frequency {
    char value;
    short count;
    Frequency(char value, short count) {
        this.value = value;
        this.count = count;
    }
}
