#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void dfs(vector<vector<pair<int, LL>>>& G, vector<LL>& save, int v, int p, LL sum) {
    save[v] = sum;

    for(auto& nei : G[v]) {
        if(nei.first != p) {
            dfs(G, save, nei.first, v, sum ^ nei.second);
        }
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<vector<pair<int, LL>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        LL W;
        cin >> U >> V >> W;

        U -= 1;
        V -= 1;
        
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    vector<LL> save(N, 0LL);
    dfs(G, save, 0, -1, 0LL);

    array<LL, 60> cnt{0LL};
    for(int i = 0; i < 60; i++) {
        int tot_b0 = 0;
        int tot_b1 = 0;
        for(int u = 0; u < N; u++) {
            if(save[u] & (1LL << i)) {
                tot_b1 += 1;
            } else {
                tot_b0 += 1;
            }
        } 

        for(int u = 0; u < N; u++) {
            if(save[u] & (1LL << i)) {
                tot_b1 -= 1;
                cnt[i] += tot_b0;
            } else {
                tot_b0 -= 1;
                cnt[i] += tot_b1;
            }
        }
    }

    LL ans = 0LL;
    LL two = 1LL;
    for(int i = 0; i < 60; i++) {
        ans += two * (cnt[i] % MOD) % MOD;
        ans %= MOD;
        two *= 2LL;
        two %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
