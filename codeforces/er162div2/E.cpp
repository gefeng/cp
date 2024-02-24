#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

std::map<int, int> dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, int64_t& ans) {
    std::map<int, int> m;
    std::map<int, int> cnt_c;

    int64_t res = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            std::map<int, int> mc = dfs(G, A, nei, v, ans);
            if(mc.size() > m.size()) {
                std::swap(mc, m);
            }

            for(auto [c, cnt] : mc) {
                if(m.find(c) != m.end() && c != A[v]) {
                    res += (int64_t)m[c] * cnt;
                }
                m[c] += cnt;
            }
        }
    } 

    ans += res + m[A[v]];
    m[A[v]] = 1;

    return m;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int64_t ans = 0;
    dfs(G, A, 0, -1, ans); 
    
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
