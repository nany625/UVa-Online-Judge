#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> elephant;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int W, S;
    while(cin >> W >> S)
        elephant.emplace_back(W, S, elephant.size());
    sort(elephant.begin(), elephant.end());
    vector<int> tail, tailIdx, pre(elephant.size(), -1);
    for(int i = 0; i < elephant.size(); ++i) {
        int pos = lower_bound(tail.begin(), tail.end(), get<1>(elephant[i]), greater<>()) - tail.begin();
        if(pos == tail.size()) {
            tail.push_back(get<1>(elephant[i]));
            tailIdx.push_back(i);
        } else {
            tail[pos] = get<1>(elephant[i]);
            tailIdx[pos] = i;
        }
        if(pos > 0)
            pre[i] = tailIdx[pos - 1];
    }
    int last = tailIdx.back();
    vector<int> ans;
    while(last != -1) {
        ans.push_back(get<2>(elephant[last]));
        last = pre[last];
    }
    cout << tail.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] + 1 << '\n';
    return 0;
}
