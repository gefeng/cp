#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs1(std::vector<std::vector<std::pair<int, int>>>& G, int v, std::vector<int>& vis) {
    int cnt = 1;
    vis[v] = 1;
    
    for(auto [nei, _] : G[v]) {
        if(!vis[nei]) {
            cnt += dfs1(G, nei, vis);
        }
    }
    
    return cnt;
}

bool assign(int N, std::vector<std::vector<std::pair<int, int>>>& G, int v, int r, int& used, std::vector<int>& val) {
    if(r < 0 || r >= N || (used & (1 << r))) {
        return false;
    }

    used |= 1 << r;
    val[v] = r;

    for(auto [nei, w] : G[v]) {
        if(val[nei] == -1) {
            if(!assign(N, G, nei, r + w, used, val)) {
                return false;
            }
        } else {
            if(val[nei] != r + w) {
                return false;
            }
        }
    }

    return true;
}

void unassign(std::vector<std::vector<std::pair<int, int>>>& G, int v, int& used, std::vector<int>& val) {
    used ^= 1 << val[v];
    val[v] = -1;

    for(auto [nei, _] : G[v]) {
        if(val[nei] != -1) {
            unassign(G, nei, used, val);
        }
    }
}

void dfs2(int N, std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& components, int i, int used, std::vector<int>& val, std::vector<std::vector<int>>& rank) {
    if(i == components.size()) {
        for(int j = 0; j < N; j++) {
            if(val[j] != -1) {
                rank[j][val[j]] = 1;
            }
        } 
        return;
    }

    for(int x = 0; x < N; x++) {
        if(used & (1 << x)) {
            continue;
        }

        if(assign(N, G, components[i], x, used, val)) {
            dfs2(N, G, components, i + 1, used, val, rank);
        } 
        unassign(G, components[i], used, val);
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, -W);
        G[V].emplace_back(U, W);
    }

    std::vector<int> ans(N, -1);
    std::vector<int> components;
    std::vector<int> vis(N, 0);
    int single = -1;
    int cnt_single = 0;
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            int cnt = dfs1(G, i, vis);
            if(cnt > 1) {
                components.push_back(i);
            } else {
                single = i;
                cnt_single += 1;
            }
        } 
    }

    if(cnt_single == 1) {
        components.push_back(single);
    } 

    int size = components.size();
    if(size) {
        std::vector<int> val(N, -1);
        std::vector<std::vector<int>> rank(N, std::vector<int>(N, 0));
        dfs2(N, G, components, 0, 0, val, rank);

        for(int i = 0; i < N; i++) {
            int cnt = 0;
            int v = 0;
            for(int j = 0; j < N; j++) {
                if(rank[i][j]) {
                    cnt += 1;
                    v = j;
                }
            }

            if(cnt == 1) {
                ans[i] = v + 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
