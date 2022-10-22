#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1e4;

bool is_ok(vector<int>& v, int t) {
    int n = v.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(2 * MAX + 10, false));

    dp[0][MAX] = true;
    for(int i = 1; i <= n; i++) {
        int x = v[i - 1];
        for(int j = -MAX + x; j <= MAX - x; j++) {
            int l = j - x + MAX;
            int r = j + x + MAX;
            dp[i][j + MAX] = dp[i - 1][l] || dp[i - 1][r];
        }
    }

    return dp[n][t + MAX];
}

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> h;
    vector<int> v;
    h.reserve(N);
    v.reserve(N);

    for(int i = 1; i < N; i += 2) {
        v.push_back(A[i]);    
    }

    for(int i = 2; i < N; i += 2) {
        h.push_back(A[i]);
    }

    cout << (is_ok(h, abs(X - A[0])) && is_ok(v, abs(Y)) ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
