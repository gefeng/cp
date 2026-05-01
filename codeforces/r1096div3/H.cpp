#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

int dfs1(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& cnt, int64_t& ans) {
    if(G[v].size() == 1 && p != -1) {
        ans++;
        cnt[v] = 1;
        return 1;
    }

    int leaves = 0;
    for(int u : G[v]) {
        if(u != p) {
            leaves += dfs1(G, u, v, cnt, ans);
        }
    }

    cnt[v] = leaves;
    if(leaves % 2 == 1 && p != -1) {
        ans++;
    }

    return leaves;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, int bal, std::vector<int>& cnt, int& max_v) {
    if(p != -1) {
        bal += cnt[v] % 2 == 1 ? 1 : -1;
    }

    if(G[v].size() == 1) {
        max_v = std::max(max_v, bal);
        return;
    }

    for(int u : G[v]) {
        if(u != p) {
            dfs2(G, u, v, bal, cnt, max_v);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int root = -1;
    for(int v = 0; v < N; v++) {
        if(G[v].size() > 1) {
            root = v;
            break;
        }
    }

    int64_t ans = 0;
    std::vector<int> cnt(N, 0);
    dfs1(G, root, -1, cnt, ans);

    if(cnt[root] % 2 == 1) {
        int max_v = 0;
        dfs2(G, root, -1, 0, cnt, max_v);
        ans -= max_v;
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
