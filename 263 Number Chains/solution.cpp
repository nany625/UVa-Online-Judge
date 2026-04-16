#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while(cin >> num && num != 0) {
        cout << "Original number was " << num << '\n';
        unordered_set<int> nums;
        do {
            nums.insert(num);
            vector<int> digits;
            while(num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
            sort(digits.begin(), digits.end());
            int desc = 0;
            for(int digit : digits)
                desc = 10 * desc + digit;
            int asc = 0;
            for(int i = digits.size() - 1; i >= 0; --i)
                asc = 10 * asc + digits[i];
            num = asc - desc;
            cout << asc << " - " << desc << " = " << num << '\n';
        } while(!nums.count(num));
        cout << "Chain length " << nums.size() << "\n\n";
    }
    return 0;
}
