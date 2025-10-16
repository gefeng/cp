#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <ranges>

void dfs(int M, std::vector<int>& a, int i, int mask, int sum, std::vector<std::map<int, int>>& m) {
    int n = a.size();
    if(i == n) {
        int b = mask & (1 << (n - 1)) ? 1 : 0;
        m[b][sum] += 1;
        return;
    }

    dfs(M, a, i + 1, mask, sum, m);
    
    if(i == 0 || (i && !(mask & (1 << (i - 1))))) {
        dfs(M, a, i + 1, mask | (1 << i), (sum + a[i]) % M, m);
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::map<int, int>> lhs(2);
    std::vector<std::map<int, int>> rhs(2);

    std::vector<int> a;
    std::vector<int> b;
    for(int i = 0; i < N / 2; i++) {
        a.push_back(A[i]);
    }

    for(int i = N / 2; i < N; i++) {
        b.push_back(A[i]);
    }

    std::ranges::reverse(b);

    dfs(M, a, 0, 0, 0, lhs);
    dfs(M, b, 0, 0, 0, rhs);
    
    int64_t ans = 0;
    for(auto [s, f] : lhs[0]) {
        int t = (M - s) % M;
        for(int i = 0; i < 2; i++) {
            if(rhs[i].find(t) != rhs[i].end()) {
                ans += static_cast<int64_t>(f) * rhs[i][t];
            }
        }
    }

    for(auto [s, f] : lhs[1]) {
        int t = (M - s) % M;
        if(rhs[0].find(t) != rhs[0].end()) {
            ans += static_cast<int64_t>(f) * rhs[0][t];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
