#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int t, int v, int depth, int& cnt) {
    int max_d = 0;
    for(int u : G[v]) {
        max_d = std::max(max_d, dfs(G, t, u, depth + 1, cnt) + 1); 
    }

    if(max_d == t - 1 && depth > 1) {
        cnt += 1;
        return -1;
    }

    return max_d;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    auto check = [&](int t) {
        int cnt = 0;
        dfs(G, t, 0, 0, cnt);
        return cnt <= K;
    };

    int lo = 1;
    int hi = N - 1;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        if(check(mid)) {
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
