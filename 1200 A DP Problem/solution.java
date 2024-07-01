import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
    	    StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int t = (int)st.nval;
            while(t-- > 0) {
                String[] equation = br.readLine().split("=");
                int CoefficientOfX = 0, Const = 0, coefficient = 0;
            	boolean plus = true, EmptyCoefficient = true;
            	for(int i = 0; i < equation[0].length(); ++i) {
            		if(Character.isDigit(equation[0].charAt(i))) {
    					coefficient = coefficient * 10 + equation[0].charAt(i) - '0';
    					EmptyCoefficient = false;
    				} else if(equation[0].charAt(i) == '+') {
    					if(plus)
    						Const += coefficient;
    					else {
    						Const -= coefficient;
    						plus = true;
    					}
    					coefficient = 0;
    					EmptyCoefficient = true;
    				} else if(equation[0].charAt(i) == '-') {
    					if(plus) {
    						Const += coefficient;
    						plus = false;
    					} else
    						Const -= coefficient;
    					coefficient = 0;
    					EmptyCoefficient = true;
    				} else if(equation[0].charAt(i) == 'x') {
    					if(EmptyCoefficient) {
    						if(plus)
    							++CoefficientOfX;
    						else
    							--CoefficientOfX;
    					} else{
    						if(plus)
    							CoefficientOfX += coefficient;
    						else
    							CoefficientOfX -= coefficient;
    					}
    					coefficient = 0;
    				}
            	}
            	if(plus)
    				Const += coefficient;
    			else
    				Const -= coefficient;
    			plus = true;
    			coefficient = 0;
    			EmptyCoefficient = true;
    			for(int i = 0; i < equation[1].length(); ++i) {
            		if(Character.isDigit(equation[1].charAt(i))) {
    					coefficient = coefficient * 10 + equation[1].charAt(i) - '0';
    					EmptyCoefficient = false;
    				} else if(equation[1].charAt(i) == '+') {
    					if(plus)
    						Const -= coefficient;
    					else {
    						Const += coefficient;
    						plus = true;
    					}
    					coefficient = 0;
    					EmptyCoefficient = true;
    				} else if(equation[1].charAt(i) == '-') {
    					if(plus) {
    						Const -= coefficient;
    						plus = false;
    					} else
    						Const += coefficient;
    					coefficient = 0;
    					EmptyCoefficient = true;
    				}
    				else if(equation[1].charAt(i) == 'x') {
    					if(EmptyCoefficient) {
    						if(plus)
    							--CoefficientOfX;
    						else
    							++CoefficientOfX;
    					} else{
    						if(plus)
    							CoefficientOfX -= coefficient;
    						else
    							CoefficientOfX += coefficient;
    					}
    					coefficient = 0;
    				}
            	}
            	if(plus)
    				Const -= coefficient;
    			else
    				Const += coefficient;
    			if(CoefficientOfX == 0 && Const == 0)
    				System.out.println("IDENTITY");
    			else if(CoefficientOfX == 0 && Const != 0)
    				System.out.println("IMPOSSIBLE");
    			else
    				System.out.println((int)Math.floor((double)Const / CoefficientOfX * (-1)));
            }
	    } catch(IOException e) {}
	}
}
