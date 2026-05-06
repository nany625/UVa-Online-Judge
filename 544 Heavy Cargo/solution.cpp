#include <bits/stdc++.h>
using namespace std;

const int MAXE = 200;
const int MAXV = 19900;
array<int, MAXE> root, ranks;
array<tuple<int, int, int>, MAXV> edges;

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(ranks[x] > ranks[y])
            root[y] = x;
        else if(ranks[x] < ranks[y])
            root[x] = y;
        else
            ++ranks[root[y] = x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int scenarios = 0, n, r;
    while(cin >> n >> r && n != 0) {
        unordered_map<string, int> cityNum;
        string city1, city2;
        int w;
        for(int i = 0; i < r; ++i) {
            cin >> city1 >> city2 >> w;
            if(!cityNum.count(city1))
                cityNum[city1] = cityNum.size();
            if(!cityNum.count(city2))
                cityNum[city2] = cityNum.size();
            edges[i] = {cityNum[city1], cityNum[city2], w};
        }
        sort(edges.begin(), edges.begin() + r, [](auto& a, auto& b) {
            return get<2>(a) > get<2>(b);
        });
        iota(root.begin(), root.begin() + n, 0);
        fill(ranks.begin(), ranks.begin() + n, 0);
        cin >> city1 >> city2;
        int s = cityNum[city1], t = cityNum[city2];
        for(int i = 0; i < r; ++i) {
            unite(get<0>(edges[i]), get<1>(edges[i]));
            if(find(s) == find(t)) {
                cout << "Scenario #" << ++scenarios << '\n' << get<2>(edges[i]) << " tons\n\n";
                break;
            }
        }
    }
    return 0;
}
