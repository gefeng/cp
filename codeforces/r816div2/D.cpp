#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& vis, std::vector<int>& color, int b, int v, std::vector<int>& seen) {
    seen.push_back(v);
    vis[v] = 1;

    for(auto [nei, x] : g[v]) {
        if((x & (1 << b)) == 0) {
            color[v] = 0;
            color[nei] = 0;
        }
    }

    for(auto [nei, x] : g[v]) {
        if(!vis[nei]) {
            dfs(g, vis, color, b, nei, seen);
        }
    }
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::tuple<int, int, int>> A(Q);
    for(int i = 0; i < Q; i++) {
        auto& [x, y, z] = A[i];
        std::cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        if(x > y) {
            std::swap(x, y);
        }
    }

    std::vector<std::vector<std::pair<int, int>>> g(N);
    std::vector<int> ans(N, 0);
    std::vector<int> color(N, 1);
    std::vector<int> vis1(N, 0);
    std::vector<int> vis2(N, 0);

    for(auto [i, j, x] : A) {
        g[i].emplace_back(j, x);
        g[j].emplace_back(i, x);
    }

    for(int v = 0; v < N; v++) {
        std::ranges::sort(g[v]);
    }

    for(int b = 29; b >= 0; b--) {
        for(int v = 0; v < N; v++) {
            color[v] = 1;
            vis1[v] = 0;
            vis2[v] = 0;
        }

        for(int v = 0; v < N; v++) {
            if(!vis1[v]) {
                std::vector<int> seen;
                dfs(g, vis1, color, b, v, seen);

                std::ranges::sort(seen);

                for(int x : seen) {
                    if(color[x] == 1) {
                        bool flip = true;
                        for(auto [nei, _] : g[x]) {
                            if(nei == x || color[nei] == 0) {
                                flip = false;
                                break;
                            }
                        }
                        if(flip) {
                            color[x] = 0;
                        }
                    }
                }
            }
        }

        for(int v = 0; v < N; v++) {
            if(color[v]) {
                ans[v] |= 1 << b;
            }
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
