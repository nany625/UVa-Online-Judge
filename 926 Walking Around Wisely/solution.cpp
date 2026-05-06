#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
array<array<long, MAXN + 1>, MAXN + 1> ways;
vector<bitset<MAXN + 1>> Nblock(MAXN + 1);
vector<bitset<MAXN + 1>> Eblock(MAXN + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C;
    cin >> C;
    while(C--) {
        int N;
        cin >> N;
        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;
        --start.first;
        --start.second;
        --end.first;
        --end.second;
        for(int i = start.second; i <= end.second; ++i) {
            Nblock[i].reset();
            Eblock[i].reset();
            for(int j = start.first; j <= end.first; ++j)
                ways[i][j] = 0;
        }
        int W;
        cin >> W;
        pair<int, int> P;
        string D;
        while(W--) {
            cin >> P.first >> P.second >> D;
            --P.first;
            --P.second;
            switch(D[0]) {
                case 'N':
                    Nblock[P.second][P.first] = 1;
                    break;
                case 'E':
                    Eblock[P.second][P.first] = 1;
                    break;
                case 'S':
                    Nblock[P.second - 1][P.first] = 1;
                    break;
                case 'W':
                    Eblock[P.second][P.first - 1] = 1;
            }
        }
        ways[start.second][start.first] = 1;
        for(int i = start.second; i <= end.second; ++i) {
            for(int j = start.first; j <= end.first; ++j) {
                if(!Eblock[i][j])
                    ways[i][j + 1] += ways[i][j];
                if(!Nblock[i][j])
                    ways[i + 1][j] += ways[i][j];
            }
        }
        cout << ways[end.second][end.first] << '\n';
    }
    return 0;
}
