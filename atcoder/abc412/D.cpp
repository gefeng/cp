#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> E(N, std::vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        E[U][V] = 1;
        E[V][U] = 1;
    }

    int ans = INF;

    auto count = [&](std::vector<int>& a) {
        int min_v = INF;
        int n = a.size();
        int tot = 0;
        std::vector<int> p(n, 0);
        std::iota(p.begin(), p.end(), 0);

        std::vector<std::vector<int>> vis(N, std::vector<int>(N, 0));
        for(int v : a) {
            for(int u : a) {
                if(E[u][v] && !vis[u][v]) {
                    tot += 1;
                    vis[u][v] = 1;
                    vis[v][u] = 1;
                }
            }
        }

        do {
            int have = 0;
            int need = 0;
            for(int j = 0; j < n; j++) {
                int pre = a[p[(j - 1 + n) % n]]; 
                int now = a[p[j]];
                if(E[pre][now]) {
                    have += 1;  
                } else {
                    need += 1;
                }
            }

            min_v = std::min(min_v, tot - have + need);
        } while(std::next_permutation(p.begin(), p.end()));

        return min_v;
    };

    {
        std::vector<int> a(N, 0);
        std::iota(a.begin(), a.end(), 0);

        ans = std::min(ans, count(a));
    }

    {
        for(int mask = 1; mask < (1 << N); mask++) {
            int cnt = __builtin_popcount(mask);
            if(cnt < 3 || N - cnt < 3) {
                continue;
            }

            std::vector<int> a;
            std::vector<int> b;
            for(int i = 0; i < N; i++) {
                if(mask & (1 << i)) {
                    a.push_back(i);
                } else {
                    b.push_back(i);
                }
            }

            int x = 0;
            for(int v : a) {
                for(int u : b) {
                    if(E[v][u]) {
                        x += 1;
                    }
                }
            }

            x += count(a) + count(b);
            
            ans = std::min(ans, x);
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
