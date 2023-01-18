#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};
const int INF = 2e9;

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> G(H, vector<int>(W, 0));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }

    auto flip = [&](auto& v) {
        for(int i = 0; i < W; i++) {
            v[i] ^= 1;
        }
    };

    auto has_isolate = [&](const auto& r0, const auto& r1, const auto& r2) -> bool {
        for(int c = 0; c < W; c++) {
            bool is_isolate = true;
            if(c && r1[c - 1] == r1[c]) {
                is_isolate = false;
            }
            if(c < W - 1 && r1[c] == r1[c + 1]) {
                is_isolate = false;
            }
            if(r0[c] == r1[c] || r2[c] == r1[c]) {
                is_isolate = false;
            }
            if(is_isolate) {
                return true;
            }
        } 
        return false;
    };

    // dp[i][j] minimum operations to make i - 1 rows no isolated elements, 
    // i - 1 and i rows are flipped based on state j
    vector<int> dp(4, INF);  // minimum operations to make i - 1 no isolated elements
    for(int i = 0; i < 4; i++) {
        vector<int> r0(W, -1);
        vector<int> r1(G[0]);
        vector<int> r2(G[1]);
        
        int cnt = 0;
        if(i & 2) {
            flip(r1);
            cnt += 1;
        }
        if(i & 1) {
            flip(r2);
            cnt += 1;
        }

        if(!has_isolate(r0, r1, r2)) {
            dp[i] = cnt; 
        }
    }

    for(int i = 3; i <= H; i++) {
        vector<int> ndp(4, INF);

        for(int j = 0; j < 4; j++) {
            if(dp[j] == INF) {
                continue;
            }

            for(int k = 0; k < 2; k++) {
                vector<int> r0(G[i - 3]);
                vector<int> r1(G[i - 2]);
                vector<int> r2(G[i - 1]);
                if(j & 2) {
                    flip(r0);
                }
                if(j & 1) {
                    flip(r1);
                }
                if(k == 1) {
                    flip(r2);
                }

                if(!has_isolate(r0, r1, r2)) {
                    int state = ((j & 1) << 1) | k;
                    ndp[state] = min(ndp[state], dp[j] + k);
                }
            }
        }

        swap(dp, ndp);
    }

    int ans = INF;
    for(int i = 0; i < 4; i++) {
        if(dp[i] == INF) {
            continue;
        }
        
        vector<int> r0(G[H - 2]);
        vector<int> r1(G[H - 1]);
        vector<int> r2(W, -1);

        if(i & 2) {
            flip(r0);
        }
        if(i & 1) {
            flip(r1);
        }
        
        if(!has_isolate(r0, r1, r2)) {
            ans = min(ans, dp[i]);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
