#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 2000000;
unsigned int mark[(MAX_NUM >> 5) + 1];
vector<int> primes;
vector<pair<int, int>> answers(MAX_NUM + 1);

bool get(int n) {
    return mark[n >> 5] & (1u << (n & 31));
}

void setBit(int n) {
    mark[n >> 5] |= 1u << (n & 31);
}

void eulerSieve() {
    answers[1].first = 1;
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!get(n)) {
            primes.push_back(n);
            answers[n].second = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            setBit(temp);
            answers[temp].second = answers[primes[i]].second + answers[n].second;
            if(n % primes[i] == 0)
                break;
        }
        answers[n].first = n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    stable_sort(answers.begin(), answers.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
    int cases = 0, n;
    while(cin >> n && n != 0)
        cout << "Case " << ++cases << ": " << answers[n].first << '\n';
    return 0;
}
