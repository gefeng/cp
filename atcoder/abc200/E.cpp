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
    int N;
    LL K;
    cin >> N >> K;    

    vector<vector<LL>> dp(4, vector<LL>(3 * N + 1, 0LL));
    vector<vector<LL>> ds(4, vector<LL>(3 * N + 5, 0LL));

    dp[0][0] = 1LL;

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= i * N + 1; j++) {
            ds[i - 1][j] = ds[i - 1][j - 1] + dp[i - 1][j - 1];
        }

        for(int j = i; j <= i * N; j++) {
            /*for(int k = 1; k <= min(j, N); k++) {
                dp[i][j] += dp[i - 1][j - k];
            }*/

            int l = max(0, j - N);
            int r = j - 1;
            dp[i][j] = ds[i - 1][r + 1] - ds[i - 1][l];
        }
        
    }

    for(int i = 1; i <= 3 * N; i++) {
        if(K > dp[3][i]) {
            K -= dp[3][i];
        } else {
            for(int j = 1; j <= N; j++) {
                if(K > dp[2][i - j]) {
                    K -= dp[2][i - j];
                } else {
                    //cout << K << '\n';
                    for(int k = max(1, i - j - N); k <= N; k++) {
                        K -= 1;
                        if(K == 0) {
                            cout << j << ' ' << k << ' ' << i - j - k << '\n';
                            return;
                        }
                    }
                }
            }
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
