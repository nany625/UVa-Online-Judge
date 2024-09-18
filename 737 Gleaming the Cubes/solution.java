import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	int cubes;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (cubes = (int)st.nval) != 0) {
    	    st.nextToken();
    	    int x = (int)st.nval;
    	    st.nextToken();
    	    int y = (int)st.nval;
    	    st.nextToken();
    	    int z = (int)st.nval;
    	    st.nextToken();
    	    int dist = (int)st.nval;
    	    int minX = x, maxX = x + dist, minY = y, maxY = y + dist, minZ = z, maxZ = z + dist;
    	    --cubes;
    	    while(cubes-- > 0) {
    	        st.nextToken();
        	    x = (int)st.nval;
        	    st.nextToken();
        	    y = (int)st.nval;
        	    st.nextToken();
        	    z = (int)st.nval;
        	    st.nextToken();
        	    dist = (int)st.nval;
        	    minX = Math.max(minX, x);
        	    maxX = Math.min(maxX, x + dist);
        	    minY = Math.max(minY, y);
        	    maxY = Math.min(maxY, y + dist);
        	    minZ = Math.max(minZ, z);
        	    maxZ = Math.min(maxZ, z + dist);
    	    }
    	    if(maxX < minX || maxY < minY || maxZ < minZ)
	            output.append("0\n");
	        else
	            output.append((maxX - minX) * (maxY - minY) * (maxZ - minZ)).append('\n');
    	}
	    System.out.print(output);
	}
}
