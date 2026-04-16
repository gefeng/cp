#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::pair<int, int>> E;
    for(int i = 0; i < Q; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        E.emplace_back(U, V);
    }

    std::vector<std::vector<int>> groups(N);
    std::vector<int> which(N, 0);
    std::vector<int> color(N, 0);
    std::vector<int> cnt_b(N, 0);

    std::iota(which.begin(), which.end(), 0);
    for(int i = 0; i < N; i++) {
        groups[i].push_back(i);
    }

    int black = 0;
    for(auto [u, v] : E) {
        int x = which[u];
        int y = which[v];

        if(x == y) {
            if(color[u] == color[v]) {
                black = -1;
            }
        } else {
            if(black != -1) {
                int n = groups[x].size();
                int m = groups[y].size();
                int flip = color[u] == color[v];
                int min_x = std::min(cnt_b[x], n - cnt_b[x]);
                int min_y = std::min(cnt_b[y], m - cnt_b[y]);
                black -= min_x + min_y;
                if(n <= m) {
                    while(!groups[x].empty()) {
                        int i = groups[x].back();
                        groups[x].pop_back();
                        color[i] ^= flip;
                        which[i] = y;
                        groups[y].push_back(i);
                        if(color[i]) {
                            cnt_b[y]++;
                        }
                    }
                    black += std::min(cnt_b[y], n + m - cnt_b[y]);
                } else {
                    while(!groups[y].empty()) {
                        int i = groups[y].back();
                        groups[y].pop_back();
                        color[i] ^= flip;
                        which[i] = x;
                        groups[x].push_back(i);
                        if(color[i]) {
                            cnt_b[x]++;
                        }
                    }
                    black += std::min(cnt_b[x], n + m - cnt_b[x]);
                }
            }
        }

        std::cout << black << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
