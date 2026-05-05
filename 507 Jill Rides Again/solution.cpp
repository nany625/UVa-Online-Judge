#include <bits/stdc++.h>
using namespace std;

const int MAXS = 20000;
vector<int> n(MAXS - 1);

pair<int, int> maxSubarraySum(int s) {
    pair<int, int> ans = {0, 0};
    int mx = n[0], temp = n[0], start = 0;
    for(int i = 1; i < s - 1; ++i) {
        if(temp + n[i] < n[i]) {
            temp = n[i];
            start = i;
        } else
            temp += n[i];
        if(mx < temp) {
            mx = temp;
            ans = {start, i};
        } else if(mx == temp && ans.second - ans.first < i - start)
            ans = {start, i};
    }
    if(mx <= 0)
        return {-1, -1};
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b;
    cin >> b;
    for(int i = 1; i <= b; ++i) {
        int s;
        cin >> s;
        for(int j = 0; j < s - 1; ++j)
            cin >> n[j];
        auto ans = maxSubarraySum(s);
        if(ans.first == -1)
            cout << "Route " << i << " has no nice parts\n";
        else
            cout << "The nicest part of route " << i << " is between stops " << ans.first + 1 << " and " << ans.second + 2 << '\n';
    }
    return 0;
}
