#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& a) {
    a.push_back(v);
    for(int u : G[v]) {
        if(u != p) {
            dfs(G, u, v, a);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        degree[U] += 1;
        degree[V] += 1;
    }
    
    auto query = [&](int u, int v) {
        std::cout << "? " << u + 1 << ' ' << v + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> a;
    dfs(G, 0, -1, a);

    int ans = -1;
    for(int i = 0; i < N; i += 2) {
        if(i == N - 1) {
            ans = a[i];
            break;
        }
        int u = a[i];
        int v = a[i + 1];
        if(query(u, v)) {
            if(query(u, u)) {
                ans = u;
            } else {
                ans = v;
            }
            break;
        }
    }

    std::cout << "! " << ans + 1 << std::endl;
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
