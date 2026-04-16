#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

bitset<(MAXN >> 1) + 1> mark;
vector<int> primes;
vector<pair<int, long>> answers;

void eulerSieve() {
    for(int n = 3; n <= MAXN >> 1; n += 2) {
        if(!mark[n >> 1]) {
            primes.push_back(n);
            int tempSum = 1, term = 2;
            while(term * n <= MAXN) {
                tempSum += term;
                answers.push_back({term * n, tempSum * (1 + n)});
                term <<= 1;
            }
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN >> 1; ++i) {
            mark[temp >> 1] = 1;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int findPos(int key) {
    return upper_bound(
        answers.begin(), 
        answers.end(), 
        key, 
        [](int val, const pair<int, long> &a) {
            return val < a.first;
        }) - answers.begin() - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    sort(answers.begin(), answers.end());
    answers[0].second = 0;
    for(int i = 1; i < answers.size(); ++i)
        answers[i].second += answers[i - 1].second - (answers[i].first << 1);
    int n;
    while(cin >> n && n != 0)
        cout << n << ' ' << (n <= 9 ? 0 : answers[findPos(n)].second) << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

bitset<(MAXN >> 1) + 1> mark;
vector<int> primes;
vector<long> answers(MAXN + 1);

void eulerSieve() {
    for(int n = 3; n <= MAXN >> 1; n += 2) {
        if(!mark[n >> 1]) {
            primes.push_back(n);
            int tempSum = 1, term = 2;
            while(1) {
                int op = term * n;
                if(op > MAXN)
                    break;
                tempSum += term;
                answers[op] = tempSum * (1 + n) - (op << 1);
                term <<= 1;
            }
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN >> 1; ++i) {
            mark[temp >> 1] = 1;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    for(int i = 11; i <= MAXN; ++i)
        answers[i] += answers[i - 1];
    int n;
    while(cin >> n && n != 0)
        cout << n << ' ' << answers[n] << '\n';
    return 0;
}
