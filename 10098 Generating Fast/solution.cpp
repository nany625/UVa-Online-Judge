#include <bits/stdc++.h>
using namespace std;

bitset<10> used;
string str;
vector<char> path(10);

void backtrack(int n, int depth) {
    if(depth == n) {
        for(int i = 0; i < n; ++i)
            cout << path[i];
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(used[i])
            continue;
        if(i > 0 && str[i - 1] == str[i] && !used[i - 1])
            continue;
        used[i] = 1;
        path[depth] = str[i];
        backtrack(n, depth + 1);
        used[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        cin >> str;
        sort(str.begin(), str.end());
        used.reset();
        backtrack(str.length(), 0);
        cout << '\n';
    }
    return 0;
}
