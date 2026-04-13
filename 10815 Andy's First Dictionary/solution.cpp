#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<string> dict;
    string word;
    char ch;
    while(cin.get(ch)) {
        if(isalpha(ch))
            word.push_back(tolower(ch));
        else {
            if(word.length() > 0)
                dict.insert(word);
            word.clear();
        }
    }
    if(!word.empty())
        dict.insert(word);
    for(string s : dict)
        cout << s << '\n';
    return 0;
}
