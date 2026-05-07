#include <bits/stdc++.h>
using namespace std;

struct Job {
    int jobNum, T, S;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int N;
        cin >> N;
        vector<Job> jobs(N);
        for(int i = 0; i < N; ++i) {
            jobs[i].jobNum = i + 1;
            cin >> jobs[i].T >> jobs[i].S;
        }
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            if(a.T * b.S != a.S * b.T)
                return a.T * b.S < a.S * b.T;
            return a.jobNum < b.jobNum;
        });
        for(int i = 0; i < N - 1; ++i)
            cout << jobs[i].jobNum << ' ';
        cout << jobs[N - 1].jobNum << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
