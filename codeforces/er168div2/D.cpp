#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e9;

bool dfs(std::vector<std::vector<int>>& G, std::vector<int64_t>& A, int v, int64_t acc) {
    if(G[v].empty()) {
        int64_t x = A[v] + acc;
        return x >= 0;
    }

    if(std::abs(acc) > MAX) {
        return false;
    }

    int64_t n_acc = acc;
    if(v != 0) {
        int64_t x = A[v] + acc;
        int64_t more = std::min(int64_t(0), x);
        n_acc += more;
    }
    for(int nei : G[v]) {
        if(!dfs(G, A, nei, n_acc)) {
            return false;
        }
    }
    return true;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        if(dfs(G, A, 0, -mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans + A[0] << '\n';
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
