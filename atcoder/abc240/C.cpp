#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;
    
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    dp[0][0] = true;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= X; j++) {
            if(j - A[i - 1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
            }
            if(j - B[i - 1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - B[i - 1]];
            }
        }
    }

    cout << (dp[N][X] ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
