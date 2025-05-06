#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>

std::pair<int, int> dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& removed, std::vector<int>& vis, std::vector<int>& pre) {
    std::pair<int, int> res = {1, v};
    vis[v] = 1;
    pre[v] = p;

    for(int nei : G[v]) {
        if(!removed[nei] && nei != p) {
            auto [d, u] = dfs(G, nei, v, removed, vis, pre);
            if(d + 1 > res.first) {
                res.first = d + 1;
                res.second = u;
            } else if(d + 1 == res.first) {
                res.second = std::max(res.second, u);
            }
        }
    }

    return res;
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

    std::vector<std::tuple<int, int, int>> ans;
    std::vector<int> removed(N, 0);

    while(true) {
        if(std::count(removed.begin(), removed.end(), 1) == N) {
            break;
        }

        std::vector<int> vis(N, 0);
        std::vector<int> pre(N, -1);
        for(int i = 0; i < N; i++) {
            if(vis[i] || removed[i]) {
                continue;
            }

            auto [d_1, v] = dfs(G, i, -1, removed, vis, pre);
            auto [d_2, u] = dfs(G, v, -1, removed, vis, pre); 
            ans.emplace_back(d_2, std::max(v, u), std::min(v, u));

            int now = u;
            while(now != -1) {
                removed[now] = 1;
                now = pre[now];
            }
        }
    }

    std::sort(ans.begin(), ans.end(), std::greater<std::tuple<int, int, int>>());

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        auto [d, u, v] = ans[i];
        std::cout << d << ' ' << u + 1 << ' ' << v + 1 << " \n"[i == size - 1];
    }
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
