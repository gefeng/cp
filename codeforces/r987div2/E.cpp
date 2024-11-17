#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int dfs(std::vector<std::vector<int>>& G, int v) {
    if(G[v].empty()) {
        return 0;
    }

    std::map<int, int> m;
    for(int nei : G[v]) {
        int d = dfs(G, nei);
        m[d] += 1;
        while(m[d] > 1) {
            m[d] -= 2;
            if(m[d] == 0) {
                m.erase(d);
            }
            d += 1;
            m[d] += 1;
        } 
    }

    int min_d = m.rbegin()->first;
    if(m.size() > 1 || G[v].size() == 1) {
        min_d += 1;
    }
    return min_d;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i + 1);
    }

    int ans = dfs(G, 0);
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
