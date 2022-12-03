#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

LL dp[1001][11][11][11]; // number of sequence whose length is i and LIS table is (a1, a2, a3).

void run_case() {
    int N, M;
    cin >> N >> M;

    dp[0][M][M][M] = 1LL;

    for(int i = 0; i < N; i++) {
        for(int a1 = 0; a1 <= M; a1++) {
            for(int a2 = 0; a2 <= M; a2++) {
                for(int a3 = 0; a3 <= M; a3++) {
                    LL cur = dp[i][a1][a2][a3];
                    for(int x = 0; x < M; x++) {
                        if(x <= a1) {
                            dp[i + 1][x][a2][a3] += cur;
                            dp[i + 1][x][a2][a3] %= MOD;
                        } else if(x <= a2) {
                            dp[i + 1][a1][x][a3] += cur;
                            dp[i + 1][a1][x][a3] %= MOD;
                        } else if(x <= a3) {
                            dp[i + 1][a1][a2][x] += cur;
                            dp[i + 1][a1][a2][x] %= MOD;
                        }
                    }
                }
            }
        }
    } 

    LL ans = 0LL;
    for(int a1 = 0; a1 < M; a1++) {
        for(int a2 = a1 + 1; a2 < M; a2++) {
            for(int a3 = a2 + 1; a3 < M; a3++) {
                ans += dp[N][a1][a2][a3];
                ans %= MOD;
            }
        } 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
