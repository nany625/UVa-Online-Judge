#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> dict;
    string word;
    int value;
    while(m--) {
        cin >> word >> value;
        dict[word] = value;
    }
    while(n--) {
        int salary = 0;
        while(cin >> word && word[0] != '.')
            salary += dict[word];
        cout << salary << '\n';
    }
    return 0;
}
