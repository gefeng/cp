#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<LL>> M(1001, vector<LL>(1001, 0LL));
    for(int i = 0; i < N; i++) {
        int H, W;
        cin >> H >> W;

        M[H][W] += (LL)H * W;
    }
    
    vector<vector<LL>> psum(1002, vector<LL>(1002, 0LL));
    for(int i = 1; i <= 1001; i++) {
        for(int j = 1; j <= 1001; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + M[i - 1][j - 1];
        }
    }

    vector<LL> ans(Q, 0);
    for(int i = 0; i < Q; i++) {
        int H1, W1, H2, W2;
        cin >> H1 >> W1 >> H2 >> W2;
        // h1 + 1, w1 + 1 => h2 - 1, w2 - 1  
        ans[i] = max(0LL, psum[H2][W2] - psum[H1 + 1][W2] - psum[H2][W1 + 1] + psum[H1 + 1][W1 + 1]);
    }

    for(int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
