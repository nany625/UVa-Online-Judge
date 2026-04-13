#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        unordered_map<string, int> subjects;
        while(N--) {
            string name;
            int days;
            cin >> name >> days;
            subjects[name] = days;
        }
        int due;
        string subject;
        cin >> due >> subject;
        if(!subjects.count(subject))
            cout << "Case " << i << ": Do your own homework!\n";
        else {
            if(due >= subjects[subject])
                cout << "Case " << i << ": Yesss\n";
            else if(due + 5 < subjects[subject])
                cout << "Case " << i << ": Do your own homework!\n";
            else
                cout << "Case " << i << ": Late\n";
        }
    }
    return 0;
}
