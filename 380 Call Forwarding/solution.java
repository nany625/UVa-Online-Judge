import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		System.out.println("CALL FORWARDING OUTPUT");
		for(int i = 1; i <= N; ++i) {
			System.out.println("SYSTEM " + i);
			ArrayList<Request> requests = new ArrayList<>();
			short source;
			while((source = sc.nextShort()) != 0)
				requests.add(new Request(source, sc.nextShort(), sc.nextShort(), sc.nextShort()));
			short time;
			while((time = sc.nextShort()) != 9000) {
				ArrayList<Short> calls = new ArrayList<>();
				calls.add(sc.nextShort());
				boolean deadEnd = false;
				int j = 0;
				while(j < requests.size() && !deadEnd) {
					if(calls.get(calls.size() - 1) == requests.get(j).source) {
						if(time >= requests.get(j).time && time <= requests.get(j).time + requests.get(j).duration) {
							if(calls.contains(requests.get(j).target))
								deadEnd = true;
							else {
								calls.add(requests.get(j).target);
								j = 0;
							}
						} else
							++j;
					} else
						++j;
				}
				System.out.printf("AT %04d CALL TO %04d RINGS %04d%n", time, calls.get(0), deadEnd ? 9999 : calls.get(calls.size() - 1));
			}
		}
		System.out.println("END OF OUTPUT");
		sc.close();
	}
}

class Request {
	short source, time, duration, target;
	Request(short source, short time, short duration, short target) {
		this.source = source;
		this.time = time;
		this.duration = duration;
		this.target = target;
	}
}
