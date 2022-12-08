#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    string min_s = S;
    string max_s = S;
    int n = S.length();

    string s = S;
    for(int i = 0; i < n; i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        min_s = min(min_s, s);
        max_s = max(max_s, s);
    }

    cout << min_s << '\n' << max_s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
