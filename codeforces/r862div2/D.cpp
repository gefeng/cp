#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, int h, std::vector<int>& d) {
    d[v] = std::max(d[v], h);

    int max_h = h;
    for(int nei : G[v]) {
        if(nei != p) {
            max_h = std::max(max_h, dfs(G, nei, v, h + 1, d));
        }
    }

    return max_h;
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

    std::vector<int> d(N, 0);
    int max_h = dfs(G, 0, -1, 0, d);

    int v = 0;
    for(int i = 0; i < N; i++) {
        if(d[i] == max_h) {
            v = i;
            break;
        }
    }

    max_h = dfs(G, v, -1, 0, d);
    for(int i = 0; i < N; i++) {
        if(d[i] == max_h) {
            v = i;
            break;
        }
    }

    int diameter = dfs(G, v, -1, 0, d);
    std::vector<int> ans(N, 1);

    std::vector<int> cnt(diameter + 1, 0);
    for(int i = 0; i < N; i++) {
        cnt[d[i]] += 1;
    }
    
    for(int k = N; k > 0; k--) {
        if(k > diameter) {
            ans[k - 1] = N;
        } else {
            ans[k - 1] = ans[k] - cnt[k] + (k == diameter ?1 : 0);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
