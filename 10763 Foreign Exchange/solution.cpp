#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n != 0) {
        vector<int> original(n), target(n);
        for(int i = 0; i < n; ++i)
            cin >> original[i] >> target[i];
        sort(original.begin(), original.end());
        sort(target.begin(), target.end());
        int i = 0;
        while(i < n && original[i] != target[i])
            ++i;
        cout << (i == n ? "YES\n" : "NO\n");
    }
    return 0;
}
