#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& A, int stones, vector<int>& dp) {
    if(stones == 0) {
        return 0;
    } 

    if(dp[stones] != -1) {
        return dp[stones];
    }

    int best = 0;
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] <= stones) {
            best = max(best, stones - dfs(A, stones - A[i], dp)); 
        }
    }

    dp[stones] = best;
    return best;
}

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(K, 0);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }

    vector<int> dp(N + 1, -1);
    int ans = dfs(A, N, dp);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
