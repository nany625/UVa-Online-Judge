#include <bits/stdc++.h>
using namespace std;

const double EPS = 0.01;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, g;
    cin >> p >> g;
    unordered_map<string, double> party;
    while(p--) {
        string name;
        double vote;
        cin >> name >> vote;
        party[name] = vote;
    }
    string P;
    int n;
    for(int i = 1; i <= g; ++i) {
        double sum = 0;
        while(cin >> P) {
            if(P.compare("<") == 0) {
                cin >> n;
                cout << "Guess #" << i << " was " << (sum + EPS < n ? "correct.\n" : "incorrect.\n");
                break;
            } else if(P.compare(">") == 0) {
                cin >> n;
                cout << "Guess #" << i << " was " << (sum + EPS > n ? "correct.\n" : "incorrect.\n");
                break;
            } else if(P.compare("<=") == 0) {
                cin >> n;
                cout << "Guess #" << i << " was " << (sum + EPS <= n ? "correct.\n" : "incorrect.\n");
                break;
            } else if(P.compare(">=") == 0) {
                cin >> n;
                cout << "Guess #" << i << " was " << (sum + EPS >= n ? "correct.\n" : "incorrect.\n");
                break;
            } else if(P[0] == '=') {
                cin >> n;
                cout << "Guess #" << i << " was " << (abs(sum - n) < EPS ? "correct.\n" : "incorrect.\n");
                break;
            } else if(P[0] == '+')
                continue;
            else
                sum += party[P];
        }
    }
    return 0;
}
