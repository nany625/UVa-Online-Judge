import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        ArrayList<Rectangle> rec = new ArrayList<>();
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_WORD && st.sval.charAt(0) == 'r') {
    	    Rectangle newRec= new Rectangle();
    	    st.nextToken();
    	    newRec.x1 = (float)st.nval;
    	    st.nextToken();
    	    newRec.y1 = (float)st.nval;
    	    st.nextToken();
    	    newRec.x2 = (float)st.nval;
    	    st.nextToken();
    	    newRec.y2 = (float)st.nval;
    	    rec.add(newRec);
    	}
    	int point = 0, size = rec.size();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    float x = (float)st.nval;
    	    st.nextToken();
    	    float y = (float)st.nval;
    	    if(10 * x == 99999 && 10 * y == 99999)
    	        break;
    	    ++point;
    	    boolean contained = false;
    	    for(int i = 0; i < size; ++i) {
                if(x > rec.get(i).x1 && y < rec.get(i).y1 && x < rec.get(i).x2 && y > rec.get(i).y2) {
                    output.append("Point " + point + " is contained in figure " + (i + 1) + "\n");
                    contained = true;
                }
            }
            if(!contained)
                output.append("Point " + point + " is not contained in any figure\n");
    	}
        System.out.print(output);
	}
}

class Rectangle {
    float x1, y1, x2, y2;
}
