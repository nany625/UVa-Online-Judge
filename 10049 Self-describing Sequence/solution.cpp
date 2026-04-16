#include <bits/stdc++.h>
using namespace std;

vector<int> f;

int binarySearch(int key) {
    int left = 0, right = f.size() - 2;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(f[mid] == key)
            return mid + 1;
        if(f[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    f.push_back(1);
    int pos = 0;
    while(f.back() <= 2000000000)
        f.push_back(f.back() + (pos += f.size() >= f[pos]));
    int n;
    while(cin >> n && n != 0)
        cout << upper_bound(f.begin(), f.end() - 1, n) - f.begin() << '\n';
    return 0;
}
