// #解法一
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> turtle;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, s;
    while(cin >> w >> s)
        turtle.emplace_back(s, w);
    sort(turtle.begin(), turtle.end());
    priority_queue<int, vector<int>> pq;
    int totalWeight = 0;
    for(auto [s, w] : turtle) {
        if(totalWeight + w <= s) {
            totalWeight += w;
            pq.push(w);
        } else if(!pq.empty() && pq.top() > w) {
            totalWeight += w - pq.top();
            pq.pop();
            pq.push(w);
        }
    }
    cout << pq.size() << '\n';
    return 0;
}

//#解法二
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> turtle;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, s;
    while(cin >> w >> s)
        turtle.emplace_back(s, w);
    sort(turtle.begin(), turtle.end());
    vector<int> dp = {0};
    for(auto [s, w] : turtle) {
        if(dp.back() + w <= s)
            dp.push_back(dp.back() + w);
        for(int i = dp.size() - 2; i >= 0; --i) {
            if(dp[i] + w <= s)
                dp[i + 1] = min(dp[i + 1], dp[i] + w);
        }
    }
    cout << dp.size() - 1 << '\n';
    return 0;
}
