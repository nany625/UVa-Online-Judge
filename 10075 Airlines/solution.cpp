#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int INF = 1e9;
const int radius = 6378;
const double PI = acos(-1);
array<array<int, MAXN>, MAXN> dist;
array<pair<double, double>, MAXN> coordinate;

double toRad(double deg) {
    return deg * PI / 180;
}

int haversine(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRad(lat1);
    lon1 = toRad(lon1);
    lat2 = toRad(lat2);
    lon2 = toRad(lon2);
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * asin(sqrt(a));
    return round(radius * c);
}

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, N, M, Q;
    while(cin >> N >> M >> Q && M != 0) {
        if(cases)
            cout << '\n';
        cout << "Case #" << ++cases << '\n';
        unordered_map<string, int> cityNum;
        string c;
        for(int i = 0; i < N; ++i) {
            cin >> c >> coordinate[i].first >> coordinate[i].second;
            cityNum[c] = i;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        string a, b;
        while(M--) {
            cin >> a >> b;
            int u = cityNum[a];
            int v = cityNum[b];
            dist[u][v] = haversine(coordinate[u].first, coordinate[u].second, coordinate[v].first, coordinate[v].second);
        }
        floydWarshall(N);
        while(Q--) {
            cin >> a >> b;
            int u = cityNum[a];
            int v = cityNum[b];
            if(dist[u][v] != INF)
                cout << dist[u][v] << " km\n";
            else
                cout << "no route exists\n";
        }
    }
    return 0;
}
