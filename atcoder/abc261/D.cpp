#include <iostream>
#include <array>
#include <vector>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(nullptr);                   // disable flushing of std::cout
    
    int n, m;
    cin >> n >> m;

    vector<int> A(n, 0);
    array<int, 5001> B = {0};

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < m; i++) {
        int x = 0;
        cin >> x;
        cin >> B[x];
    }

    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        }

        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + A[i - 1] + B[j];
        }
    }

    LL ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << '\n';
}
