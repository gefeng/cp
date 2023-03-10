#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S, T;
    cin >> S >> T;

    int n = S.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] != T[i]) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
