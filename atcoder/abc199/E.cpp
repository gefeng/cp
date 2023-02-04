#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<int> mask(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        mask[i] = mask[i - 1] << 1 | 1;
    }

    vector<vector<pair<int, int>>> prefix(N + 1);
    for(int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        prefix[X].emplace_back(Y, Z); 
    }

    vector<LL> dp(1 << N, 0LL);
    dp[0] = 1LL;

    for(int i = 0; i < (1 << N); i++) {
        int cnt_bit = __builtin_popcount(i);
        
        for(auto& p : prefix[cnt_bit]) {
            if(__builtin_popcount(mask[p.first] & i) > p.second) {
                dp[i] = 0LL;
            }
        }

        for(int j = 0; j < N; j++) {
            if((i & (1 << j)) == 0) {
                dp[i | (1 << j)] += dp[i];
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
