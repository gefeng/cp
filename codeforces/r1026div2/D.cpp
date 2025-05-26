#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t MAX = int64_t(1e16);

bool dfs(int N, std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& A, int64_t max_w, int64_t sum, int v) {
    if(v == N - 1) {
        return true;
    }

    sum += A[v];
    
    for(auto [nei, w] : G[v]) {
        if(w <= max_w && sum >= w) {
            if(dfs(N, G, A, max_w, sum, nei)) {
                return true;
            }
        }
    }

    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
    } 

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = -1;
    
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        bool ok = true;

        ok = dfs(N, G, A, mid, 0, 0);
        
        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
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
