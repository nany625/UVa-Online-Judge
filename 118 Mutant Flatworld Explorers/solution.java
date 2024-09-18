import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Coordinate> lostCoordinates = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int boundX = (int)st.nval;
        st.nextToken();
        int boundY = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int x = (int)st.nval;
            st.nextToken();
            int y = (int)st.nval;
            st.nextToken();
            char orientation = st.sval.charAt(0);
            boolean lost = false;
            st.nextToken();
            String instructions = st.sval;
            int len = instructions.length();
		    for(int i = 0; i < instructions.length() && !lost; ++i) {
    	        switch(orientation) {
                    case 'N':
                        switch(instructions.charAt(i)) {
                            case 'L':
                                orientation = 'W';
                                break;
                            case 'R':
                                orientation = 'E';
                                break;
                            case 'F':
                                if(y < boundY)
                                    ++y;
                                else if(!contain(x, y)) {
            	                    lostCoordinates.add(new Coordinate(x, y));
            	                    lost = true;
            	                }
                        }
                        break;
                    case 'E':
                        switch(instructions.charAt(i)) {
                            case 'L':
                                orientation = 'N';
                                break;
                            case 'R':
                                orientation = 'S';
                                break;
                            case 'F':
                                if(x < boundX)
                                    ++x;
                                else if(!contain(x, y)) {
            	                    lostCoordinates.add(new Coordinate(x, y));
            	                    lost = true;
            	                }
                        }
                        break;
                    case 'S':
                        switch(instructions.charAt(i)) {
                            case 'L':
                                orientation = 'E';
                                break;
                            case 'R':
                                orientation = 'W';
                                break;
                            case 'F':
                                if(y > 0)
                                    --y;
                                else if(!contain(x, y)) {
            	                    lostCoordinates.add(new Coordinate(x, y));
            	                    lost = true;
            	                }
                        }
                        break;
                    case 'W':
                        switch(instructions.charAt(i)) {
                            case 'L':
                                orientation = 'S';
                                break;
                            case 'R':
                                orientation = 'N';
                                break;
                            case 'F':
                                if(x > 0)
                                    --x;
                                else if(!contain(x, y)) {
            	                    lostCoordinates.add(new Coordinate(x, y));
            	                    lost = true;
            	                }
                        }
                }
    	    }
    	    output.append(x).append(' ').append(y).append(' ').append(orientation).append(lost ? " LOST\n" : '\n');
    	}
        System.out.print(output);
	}
	
	static boolean contain(int x, int y) {
	    for(int i = 0; i < lostCoordinates.size(); ++i) {
	        if(lostCoordinates.get(i).x == x && lostCoordinates.get(i).y == y)
	            return true;
	    }
	    return false;
	}
}

class Coordinate {
    int x, y;
    Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
