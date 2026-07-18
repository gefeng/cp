#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int MAX = 2000;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> sign(N, 0);
    std::vector<std::tuple<int, int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int O, U, V;
        std::cin >> O >> U >> V;
        U--;
        V--;
        E[i] = {O, U, V};
        if(U == V) {
            if(O == 1) {
                sign[U] = 1;
            } else {
                sign[U] = -1;
            }
        }
    }

    std::vector<std::vector<int>> g(N);
    std::vector<int> degree(N, 0);    
    for(auto [o, u, v] : E) {
        if(u == v) {
            continue;
        }
        if(o == 1) {
            if(sign[u] == -1 && sign[v] == -1) {
                std::cout << "NO" << '\n';
                return;
            }
            if(sign[u] == -1 && sign[v] == 1) {
                g[v].push_back(u);
                degree[u]++;
            } else if(sign[u] == 1 && sign[v] == -1) {
                g[u].push_back(v);
                degree[v]++;
            }
        } else {
            if(sign[u] == 1 && sign[v] == 1) {
                std::cout << "NO" << '\n';
                return;
            }
            if(sign[u] == -1 && sign[v] == 1) {
                g[u].push_back(v);
                degree[v]++;
            } else if(sign[u] == 1 && sign[v] == -1) {
                g[v].push_back(u);
                degree[u]++;
            }
        }
    }

    std::queue<int> q;
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    int now = MAX;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int v = q.front();
            q.pop();
            
            ans[v] = sign[v] * now;
            
            for(int u : g[v]) {
                if(--degree[u] == 0) {
                    q.push(u);
                }
            }
        }
        now--;
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
