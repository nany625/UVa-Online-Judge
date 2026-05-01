#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
    if(tolower(a) != tolower(b))
        return tolower(a) < tolower(b);
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    string str;
    while(cases--) {
        cin >> str;
        sort(str.begin(), str.end(),cmp);
        do {
            cout << str << '\n';
        } while(next_permutation(str.begin(), str.end(), cmp));
    }
    return 0;
}
