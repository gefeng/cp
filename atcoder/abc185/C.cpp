#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    LL L;
    cin >> L;

    vector<vector<LL>> comb(201, vector<LL>(201, 0LL));
    comb[0][0] = 1LL;

    for(int i = 1; i <= 200; i++) {
        comb[i][0] = 1LL;
        comb[i][i] = 1LL;
        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    cout << comb[L - 1][11] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
