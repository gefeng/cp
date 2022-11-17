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

void run_case() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S -= 1;
    T -= 1;
    X -= 1;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<vector<vector<LL>>> dp(K + 2, vector<vector<LL>>(N, vector<LL>(2, 0LL)));
    dp[1][S][0] = 1;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 2; k++) {
                for(int nei : G[j]) {
                    if(nei == X) {
                        dp[i + 1][nei][k ^ 1] += dp[i][j][k];
                        dp[i + 1][nei][k ^ 1] %= MOD;
                    } else {
                        dp[i + 1][nei][k] += dp[i][j][k];
                        dp[i + 1][nei][k] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[K + 1][T][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
