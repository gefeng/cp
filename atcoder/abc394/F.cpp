#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, int& ans) {
    int max_v = -1;
    std::vector<int> a;
    for(int nei : G[v]) {
        if(nei == p) {
            a.push_back(1);
            continue;
        }
        
        int d = dfs(G, nei, v, ans);
        a.push_back(d == -1 ? 1 : d);
        max_v = std::max(max_v, d);
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    int max_d = -1;
    if(G[v].size() >= 4) {
        ans = std::max(ans, 5);

        int sum = 1;
        for(int i = 0; i < std::min(4, int(a.size())); i++) {
            sum += a[i];
        }
        ans = std::max(ans, sum);
        
        max_d = sum - a[3];
    }

    return max_d;
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

    int ans = -1;
    dfs(G, 0, -1, ans);
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
