#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<LL>> d(N, vector<LL>(N, INF));    
    for(int i = 0; i < N; i++) {
        d[i][i] = 0LL;
    }

    for(int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        d[U][V] = W;
    }

    LL ans = 0LL;
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
                ans += d[i][j] == INF ? 0 : d[i][j];
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
