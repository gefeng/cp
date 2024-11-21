#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, int64_t& ans) {
    if(p != -1 && G[v].size() == 1) {
        return 0;
    } 

    int degree = G[v].size();
    
    int64_t cnt = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            int s = dfs(G, nei, v, ans);
            if(degree == 2) {
                ans += s;
                if(G[nei].size() == 2) {
                    ans -= 1;
                }
            } else if(degree == 3) {
                ans += cnt * s;
            }
            cnt += s; 
        }
    }

    if(degree == 3) {
        return cnt;
    }
    if(degree == 2) {
        return 1;
    }

    return 0;
}

void run_case() {
    int N;
    std::cin >> N;
    
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
    dfs(G, 0, -1, ans);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
