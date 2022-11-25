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

    int n = S.length();
    vector<char> v(2 * n);

    for(int i = 0; i < n; i++) {
        v[i] = S[i];
        v[2 * n - 1 - i] = S[i];
    }

    string ans = "";
    for(char c : v) {
        ans.push_back(c);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
