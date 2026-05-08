#include <bits/stdc++.h>
using namespace std;

array<set<int>, 2> v;

void solve(int n, int a, int b) {
    int temp1 = a * b, temp2 = temp1;
    vector<int> d1, d2;
    while(a > 0) {
        d1.push_back(a % 10);
        a /= 10;
    }
    while(b > 0) {
        d1.push_back(b % 10);
        b /= 10;
    }
    while(temp1 > 0) {
        d2.push_back(temp1 % 10);
        temp1 /= 10;
    }
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    if(d1 == d2)
        v[n].insert(temp2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int x = 999; x > 316; --x) {
        if(x & 1) {
            int y = x - 1;
            while(x * y >= 100000) {
                if(x % 10 != 0 || y % 10 != 0)
                    solve(0, x, y);
                y -= 2;
            }
        } else {
            int y = x;
            while(x * y >= 100000) {
                if(x % 10 != 0 || y % 10 != 0)
                    solve(0, x, y);
                --y;
            }
        }
        
    }
    for(int x = 9999; x > 3162; --x) {
        if(x & 1) {
            int y = x - 1;
            while(x * y >= 10000000) {
                if(x % 10 != 0 || y % 10 != 0)
                    solve(1, x, y);
                y -= 2;
            }
        } else {
            int y = x;
            while(x * y >= 10000000) {
                if(x % 10 != 0 || y % 10 != 0)
                    solve(1, x, y);
                --y;
            }
        }
    }
    int n;
    while(cin >> n) {
        if(n == 4)
            cout << "1260\n1530\n6880\n\n";
        else if(n == 6) {
            for(int a : v[0])
                cout << a << '\n';
            cout << '\n';
        } else {
            for(int a : v[1])
                cout << a << '\n';
            cout << '\n';
        }
    }
    return 0;
}
