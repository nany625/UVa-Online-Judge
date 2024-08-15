import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int n = (int)st.nval;
    	    Product[] products = new Product[n];
    	    for(int i = 0; i < n; ++i) {
    	        products[i] = new Product();
    	        st.nextToken();
    	        products[i].p = (int)st.nval;
    	        st.nextToken();
    	        products[i].d = (int)st.nval;
    	    }
    	    Arrays.sort(products, new Comparator<Product>() {
    	        @Override
    	        public int compare(Product p1, Product p2) {
    	            return Integer.compare(p1.d, p2.d);
    	        }
    	    });
    	    ArrayList<Integer> priorityQueue = new ArrayList<>();
    	    int size = 0;
    	    for(Product p : products) {
    	        if(p.d > size) {
    	            priorityQueue.add(p.p);
    	            ++size;
    	        } else {
    	            int minIndex = 0;
    	            for(int j = 1; j < size; ++j) {
    	                if(priorityQueue.get(j) < priorityQueue.get(minIndex))
    	                    minIndex = j;
    	            }
    	            priorityQueue.set(minIndex, Math.max(priorityQueue.get(minIndex), p.p));
    	        }
    	    }
    	    int profit = 0;
    	    for(Integer i : priorityQueue)
    	        profit += i;
    	    output.append(profit + "\n");
    	}
        System.out.print(output);
	}
}

class Product {
    int p, d;
}
