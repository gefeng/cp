#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <ranges>
#include <queue>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [a, b, c] = A[i];
        std::cin >> a >> b >> c;
    }

    std::vector<int> ans(N, 0);

    auto no_sol = [&](int i, int j) {
        auto [a1, b1, c1] = A[i];
        auto [a2, b2, c2] = A[j];
        int64_t a = a1 - a2;
        int64_t b = b1 - b2;
        int64_t c = c1 - c2;
        if(a == 0 && b == 0) {
            return true;
        }
        return b * b - 4 * a * c < 0;
    };

    std::vector<std::vector<int>> g(N);
    std::vector<std::vector<int>> rg(N);
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(no_sol(i, j)) {
                if(std::get<2>(A[i]) < std::get<2>(A[j])) {
                    g[i].push_back(j);
                    rg[j].push_back(i);
                } else {
                    g[j].push_back(i);
                    rg[i].push_back(j);
                }
            }
        }
    }

    auto longest_path = [](int n, std::vector<std::vector<int>>& g, std::vector<int>& dist) {
        std::queue<int> q;
        std::vector<int> degree(n, 0);
        for(int v = 0; v < n; v++) {
            for(int u : g[v]) {
                degree[u] += 1;
            }
        }

        for(int v = 0; v < n; v++) {
            if(degree[v] == 0) {
                q.push(v);
                dist[v] = 1;
            }
        }

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(int u : g[v]) {
                dist[u] = std::max(dist[u], dist[v] + 1);
                if(--degree[u] == 0) {
                    q.push(u);
                }
            }
        }
    };

    std::vector<int> from(N, 0);
    std::vector<int> to(N, 0);
    longest_path(N, g, from);
    longest_path(N, rg, to);

    for(int i = 0; i < N; i++) {
        ans[i] = from[i] + to[i] - 1;
    }

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
