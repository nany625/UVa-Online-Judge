import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
		br.readLine();
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    if(!firstCase)
		        output.append("\n");
		    ArrayList<ScoreBoard> scoreBoards = new ArrayList<>();
		    String s;
		    while((s = br.readLine()) != null && !s.isEmpty()) {
		        String[] tokens = s.split("\\s+");
		        short contestant = Short.parseShort(tokens[0]);
		        short problem = Short.parseShort(tokens[1]);
		        short time = Short.parseShort(tokens[2]);
		        char L = tokens[3].charAt(0);
		        int contestantPos = containContestant(scoreBoards, contestant);
		        if(contestantPos != -1) {
		            if(L == 'C') {
		                if(!scoreBoards.get(contestantPos).solvedProblems.contains(problem)) {
		                    scoreBoards.get(contestantPos).solvedProblems.add(problem);
		                    int problemPos = containProblem(scoreBoards.get(contestantPos).problemTried, problem);
		                    if(problemPos != -1) {
		                        scoreBoards.get(contestantPos).penaltyTime += time + 20 * scoreBoards.get(contestantPos).problemTried.get(problemPos).times;
		                        scoreBoards.get(contestantPos).problemTried.remove(problemPos);
		                    } else
		                        scoreBoards.get(contestantPos).penaltyTime += time;
		                }
		            } else if(L == 'I') {
		                int problemPos = containProblem(scoreBoards.get(contestantPos).problemTried, problem);
		                if(problemPos != -1)
		                    ++scoreBoards.get(contestantPos).problemTried.get(problemPos).times;
		                else
		                    scoreBoards.get(contestantPos).problemTried.add(new ProblemTried(problem, (short)1));
		            }
		        } else {
		            scoreBoards.add(new ScoreBoard(contestant));
		            if(L == 'C') {
		                scoreBoards.get(scoreBoards.size() - 1).solvedProblems.add(problem);
		                scoreBoards.get(scoreBoards.size() - 1).penaltyTime = time;
		            } else if(L == 'I')
		                scoreBoards.get(scoreBoards.size() - 1).problemTried.add(new ProblemTried(problem, (short)1));
		        }
		    }
		    Collections.sort(scoreBoards, new Comparator<ScoreBoard>() {
		        @Override
		        public int compare(ScoreBoard s1, ScoreBoard s2) {
		            if(s1.solvedProblems.size() != s2.solvedProblems.size())
		                return Integer.compare(s2.solvedProblems.size(), s1.solvedProblems.size());
		            if(s1.penaltyTime != s2.penaltyTime)
		                return Short.compare(s1.penaltyTime, s2.penaltyTime);
		            return Short.compare(s1.contestant, s2.contestant);
		        }
		    });
		    for(ScoreBoard S : scoreBoards)
		        output.append(S.contestant + " " + S.solvedProblems.size() + " " + S.penaltyTime + "\n");
		    firstCase = false;
		}
		System.out.print(output);
	}
	
	static int containContestant(ArrayList<ScoreBoard> arrayList, short key) {
	    for(int i = 0; i < arrayList.size(); ++i) {
	        if(arrayList.get(i).contestant == key)
	            return i;
	    }
	    return -1;
	}
	
	static int containProblem(ArrayList<ProblemTried> arrayList, short key) {
        for(int i = 0; i < arrayList.size(); ++i) {
            if(arrayList.get(i).problem == key)
                return i;
        }
        return -1;
    }
}

class ProblemTried {
    short problem, times;
    ProblemTried(short problem, short times) {
        this.problem = problem;
        this.times = times;
    }
}

class ScoreBoard {
    ArrayList<Short> solvedProblems;
    ArrayList<ProblemTried> problemTried;
    short contestant, penaltyTime;
    ScoreBoard(short contestant) {
        this.contestant = contestant;
        this.penaltyTime = 0;
        solvedProblems = new ArrayList<>();
        problemTried = new ArrayList<>();
    }
}
