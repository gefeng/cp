#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

int dfs(vector<vector<int>>& G, int N, int K, int vis, int v, LL t) {
    if(vis == (1 << N) - 1) {
        if(v == 0 && t == K) {
            return 1;
        }
        return 0;
    }

    if(vis & (1 << v)) {
        return 0;
    }
    
    vis |= 1 << v;

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(v != i) {
            res += dfs(G, N, K, vis, i, t + G[v][i]); 
        }
    }

    vis ^= 1 << v;
   
    return res;
}

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> G(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    cout << dfs(G, N, K, 0, 0, 0LL) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
