#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size, std::vector<int>& asc) {
    size[v] = 1;
    asc[v] = p;

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, size, asc);
            size[v] += size[nei];
        }
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> size(N, 0);
    std::vector<int> asc(N, -1);
    dfs(G, 0, -1, size, asc);

    int ans = 1;
    int v = N - 1;
    std::vector<int> nodes;
    while(asc[v] != -1) {
        int p = asc[v];
        for(int nei : G[p]) {
            if(nei != v && nei != asc[p]) {
                nodes.push_back(nei);
            }
        }
        v = p;
        ans += 1;
    }

    int n = nodes.size();
    std::sort(nodes.begin(), nodes.end(), [&](const int& i, const int& j) {
                return size[i] > size[j];
            });

    for(int i = K - 1; i < n; i++) {
        ans += size[nodes[i]];
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
