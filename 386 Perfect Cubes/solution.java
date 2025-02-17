import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 8000000;
    static int limitB = (int)Math.cbrt(MAX_NUM / 3);
    static int limitC = (int)Math.cbrt(MAX_NUM >> 1);
    static ArrayList<Answer> answers = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    for(int b = 2; b <= limitB; ++b) {
    	    for(int c = b; c <= limitC; ++c) {
    	        for(int d = c, cubeA; (cubeA = b * b * b + c * c * c + d * d * d) <= MAX_NUM; ++d) {
    	            double a = Math.cbrt(cubeA);
    	            if(a == (int)a)
    	                answers.add(new Answer((int)a, b, c, d));
    	        }
    	    }
    	}
    	answers.sort(new Comparator<Answer>() {
    	    @Override
    	    public int compare(Answer a1, Answer a2) {
    	        return Integer.compare(a1.a, a2.a);
    	    }
    	});
    	StringBuilder output = new StringBuilder();
    	for(Answer ans : answers)
    	    output.append("Cube = ").append(ans.a).append(", Triple = (").append(ans.b).append(',').append(ans.c).append(',').append(ans.d).append(")\n");
    	System.out.print(output);
	}
}

class Answer {
    int a, b, c, d;
    Answer(int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
}
