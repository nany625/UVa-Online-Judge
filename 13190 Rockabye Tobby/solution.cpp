#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<pair<string, int>> medicine(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0; i < n; ++i) {
            cin >> medicine[i].first >> medicine[i].second;
            pq.emplace(medicine[i].second, i);
        }
        while(k--) {
            auto [t, num] = pq.top();
            cout << t << ' ' << medicine[num].first << '\n';
            pq.emplace(t + medicine[num].second, num);
            pq.pop();
        }
    }
    return 0;
}
