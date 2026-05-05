#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxSubarraySum(int s) {
    pair<int, int> ans = {0, 0};
    int mx;
    cin >> mx;
    int temp = mx, start = 0, n;
    for(int i = 1; i < s - 1; ++i) {
        cin >> n;
        if(temp + n < n) {
            temp = n;
            start = i;
        } else
            temp += n;
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
        auto ans = maxSubarraySum(s);
        if(ans.first == -1)
            cout << "Route " << i << " has no nice parts\n";
        else
            cout << "The nicest part of route " << i << " is between stops " << ans.first + 1 << " and " << ans.second + 2 << '\n';
    }
    return 0;
}
