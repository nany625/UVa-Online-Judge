#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char M[21];
    int L, H;
} Data;

int main() {
	int T;
	scanf("%d", &T);
	bool firstCase = true;
	while(T--) {
		if(!firstCase)
			puts("");
		int D;
		scanf("%d", &D);
		Data datas[D];
		for(int i = 0; i < D; ++i)
			scanf("%s %d %d", datas[i].M, &datas[i].L, &datas[i].H);
		int Q;
		scanf("%d", &Q);
		while(Q--) {
			int P;
			scanf("%d", &P);
			int count = 0, curr;
			for(int i = 0; i < D && count <= 1; ++i) {
				if(P >= datas[i].L && P <= datas[i].H){
					++count;
					curr = i;
				}
			}
			if(count == 1)
				printf("%s\n", datas[curr].M);
			else
				puts("UNDETERMINED");
		}
	}
	return 0;
}
