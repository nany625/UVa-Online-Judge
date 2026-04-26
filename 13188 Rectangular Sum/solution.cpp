#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int inv2 = MOD + 1 >> 1;
const int inv6 = 166666668;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        long n;
        cin >> n;
        long startRow = ((n >> 1) + 1) % MOD;
        long rows = (n - startRow + 1) % MOD;
        long cols = (rows + ((n & 1) == 0)) % MOD;
        long topLeft = startRow * (startRow - 1) % MOD * inv2 % MOD;
        ++topLeft;
        long topRight = (topLeft + startRow - 1) % MOD;
        long sum1 = (topLeft + topRight) * cols % MOD * inv2 % MOD;
        long part1 = rows * sum1 % MOD;
        long part2 = rows * (rows - 1) % MOD * inv2 % MOD * startRow % MOD;
        long part3 = (rows - 1) * rows % MOD * (rows + 1) % MOD * inv6 % MOD;
        long ans = (part1 + (part2 + part3) % MOD * cols % MOD) % MOD;
        cout << "Case #" << i << ": " << ans << '\n';
    }
    return 0;
}
