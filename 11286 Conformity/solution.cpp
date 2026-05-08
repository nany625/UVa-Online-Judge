#include <bits/stdc++.h>
using namespace std;

array<short, 5> courses;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n != 0) {
        unordered_map<long, int> combinations;
        while(n--) {
            for(int i = 0; i < 5; ++i)
                cin >> courses[i];
            sort(courses.begin(), courses.end());
            long temp = 0;
            for(short c : courses)
                temp = 1000 * temp + c;
            ++combinations[temp];
        }
        int max = 0, students = 0;
        for(auto it : combinations) {
            if(max < it.second)
                students = max = it.second;
            else if(max == it.second)
                students += max;
        }
        cout << students << '\n';
    }
    return 0;
}
