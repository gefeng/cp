#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<std::vector<int>> pos(K + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    }

    std::vector<int64_t> best(N, INF); 
    for(int p : pos[K]) {
        best[p] = 0;
    }

    for(int v = K - 1; v >= 1; v--) {
        int n = pos[v].size();
        int m = pos[v + 1].size();
        int64_t min_v = INF; 
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && pos[v + 1][j] <= pos[v][i]) {
                min_v = std::min(min_v, best[pos[v + 1][j]] - pos[v + 1][j]);
                j += 1;
            }
            if(min_v != INF) {
                best[pos[v][i]] = std::min(best[pos[v][i]], min_v + pos[v][i]);
            }
        }
        
        min_v = INF;
        for(int i = n - 1, j = m - 1; i >= 0; i--) {
            while(j >= 0 && pos[v + 1][j] > pos[v][i]) {
                min_v = std::min(min_v, best[pos[v + 1][j]] + pos[v + 1][j]);
                j -= 1;
            }
            if(min_v != INF) {
                best[pos[v][i]] = std::min(best[pos[v][i]], min_v - pos[v][i]);
            }
        }
    }

    std::vector<int64_t> ans(N, INF); 
    
    int64_t min_v = INF;
    for(int i = 0, j = 0; i < N; i++) {
        while(j <= i) {
            if(A[j] == 1) {
                min_v = std::min(min_v, best[j] - j);
            } 
            j += 1;
        } 
        if(min_v != INF) {
            ans[i] = std::min(ans[i], i + min_v);
        }
    }

    min_v = INF;
    for(int i = N - 1, j = N - 1; i >= 0; i--) {
        while(j > i) {
            if(A[j] == 1) {
                min_v = std::min(min_v, best[j] + j);
            }
            j -= 1;
        }
        if(min_v != INF) {
            ans[i] = std::min(ans[i], min_v - i);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
