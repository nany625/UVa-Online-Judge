#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 20;
vector<vector<vector<long>>> heap(MAXSIZE, vector<vector<long>>(MAXSIZE, vector<long>(MAXSIZE)));

long maxSubarraySum(vector<long>& a) {
    long ans = a[0], temp = a[0];
    for(int i = 1; i < a.size(); ++i) {
        temp = max(a[i], temp + a[i]);
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int A, B, C;
        cin >> A >> B >> C;
        for(int i = 0; i < A; ++i) {
            for(int j = 0; j < B; ++j) {
                for(int k = 0; k < C; ++k)
                    cin >> heap[i][j][k];
            }
        }
        long ans = INT_MIN;
        for(int i = 0; i < A; ++i) {
            vector<vector<long>> sum(B, vector<long>(C));
            for(int j = i; j < A; ++j) {
                for(int k = 0; k < B; ++k) {
                    for(int l = 0; l < C; ++l)
                        sum[k][l] += heap[j][k][l];
                }
                for(int k = 0; k < B; ++k) {
                    vector<long> temp(C);
                    for(int l = k; l < B; ++l) {
                        for(int m = 0; m < C; ++m)
                            temp[m] += sum[l][m];
                        ans = max(ans, maxSubarraySum(temp));
                    }
                }
            }
        }
        cout << ans << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
