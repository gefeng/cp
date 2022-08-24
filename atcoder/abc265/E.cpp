#include <iostream>
#include <array>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<LL> D(6, 0);
    for(int i = 0; i < 6; i++) {
        cin >> D[i];
    }

    unordered_map<LL, unordered_set<LL>> O;
    for(int i = 0; i < M; i++) {
        LL X, Y;
        cin >> X >> Y;
        O[X].insert(Y); 
    }

    vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(N + 1, vector<LL>(N + 1, 0)));
    dp[0][0][0] = 1LL;

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        for(int x = 0; x <= i; x++) {
            for(int y = 0; x + y <= i; y++) {
                int z = i - x - y;
                LL r = D[0] * x + D[2] * y + D[4] * z;
                LL c = D[1] * x + D[3] * y + D[5] * z; 

                if(O.find(r) != O.end() && O[r].find(c) != O[r].end()) {
                    continue;
                }

                if(x > 0 && dp[i - 1][x - 1][y]) {
                    dp[i][x][y] += dp[i - 1][x - 1][y];
                    dp[i][x][y] %= MOD;
                }
                if(y > 0 && dp[i - 1][x][y - 1]) {
                    dp[i][x][y] += dp[i - 1][x][y - 1];
                    dp[i][x][y] %= MOD;
                }
                if(i - x - y > 0 && dp[i - 1][x][y]) {
                    dp[i][x][y] += dp[i - 1][x][y];
                    dp[i][x][y] %= MOD;
                }

                if(i == N) {
                    ans += dp[i][x][y];
                    ans %= MOD;
                }
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
