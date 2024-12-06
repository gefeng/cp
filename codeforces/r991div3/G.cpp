#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, int& ans) {
    if(G[v].size() == 1 && p != -1) {
        ans = std::max(ans, int(G[v].size()));
        return 0;
    }

    int local_max = 0;
    int max_1 = -1;
    int max_2 = -1;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        int res = dfs(G, nei, v, ans);
        
        if(res > max_1) {
            max_2 = max_1;
            max_1 = res;
        } else if(res > max_2) {
            max_2 = res;
        }
    }

    int cnt_c = p == -1 ? G[v].size() : G[v].size() - 1;

    ans = std::max(ans, int(G[v].size()));
    ans = std::max(ans, max_1 + int(G[v].size()) - 1);
    if(max_2 != -1) {
        ans = std::max(ans, max_1 + max_2 + int(G[v].size()) - 2);
    }

    local_max = std::max(cnt_c, max_1 + cnt_c - 1);
    
    return local_max;
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

    int ans = 0;
    dfs(G, 0, -1, ans);

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
