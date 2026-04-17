#include <bits/stdc++.h>
using namespace std;

vector<string> split(string line) {
    vector<string> words;
    string temp;
    for(int i = 0; i < line.length(); ++i) {
        if(isalnum(line[i]))
            temp.push_back(line[i]);
        else {
            if(!temp.empty()) {
                words.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty())
        words.push_back(temp);
    return words;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0;
    string line1, line2;
    while(getline(cin, line1) && getline(cin, line2)) {
        if(line1.empty() || line2.empty()) {
            cout << setw(2) << ++cases << ". Blank!\n";
            continue;
        }
        vector<string> words1 = split(line1);
        vector<string> words2 = split(line2);
        vector<int> dp(words2.size() + 1);
        for(int i = 0; i < words1.size(); ++i) {
            int prev = 0;
            for(int j = 1; j <= words2.size(); ++j) {
                int temp = dp[j];
                if(words1[i] == words2[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        cout << setw(2) << ++cases << ". Length of longest match: " << dp[words2.size()] << '\n';
    }
    return 0;
}
