#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> G(N, vector<int>(N, 0));   

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    int lo = 0;
    int hi = (int)1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        vector<vector<int>> g(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(G[i][j] > mid) {
                    g[i][j] = 1;
                }
            }
        }

        vector<vector<int>> psum(N + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + g[i - 1][j - 1];
            }
        }

        bool ok = false;
        for(int i = 0; i <= N - K; i++) {
            for(int j = 0; j <= N - K; j++) {
                int cnt = psum[i + K][j + K] - psum[i][j + K] - psum[i + K][j] + psum[i][j];
                if(cnt <= K * K / 2) {
                    ok = true;
                    break;
                }
            }
            if(ok) {
                break;
            }
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
