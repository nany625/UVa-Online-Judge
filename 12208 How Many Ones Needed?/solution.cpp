#include <bits/stdc++.h>
using namespace std;

long cnt(int n){
    long ans = 0, term = 1;
    do {
        int half = term;
        term <<= 1;
        ans += n / term * half;
        int temp = n % term;
        if(temp >= half)
            ans += temp - half + 1;
    } while(n >= term);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, a, b;
    while(cin >> a >> b && (a > 0 || b > 0))
        cout << "Case " << ++cases << ": " << cnt(b) - cnt(a - 1) << '\n';
    return 0;
}
