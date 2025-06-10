#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = int(1e6);
constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> pf(N);
    std::vector<int> seen(MAX + 1, 0);
    int ans = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            std::cout << 1 << '\n';
            return;
        }
        if(seen[A[i]]) {
            ans = 2;
        }
        seen[A[i]] = 1;

        int x = A[i];
        std::vector<int> p;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int cnt = 0;
                while(x % f == 0) {
                    x /= f;
                    cnt += 1;
                }
                int v = cnt % 2 == 0 ? 1 : f;
                p.push_back(v);
            }
        }
        if(x > 1) {
            p.push_back(x);
        }

        bool good = true;
        for(int f : p) {
            if(f != 1) {
                good = false;
            }
        }
        if(good) {
            std::cout << 1 << '\n';
            return;
        }

        if(p.size() == 1) {
            p.push_back(1);
        }
        if(p[0] > p[1]) {
            std::swap(p[0], p[1]);
        }
        pf[i] = {p[0], p[1]};
    }

    if(ans != -1) {
        std::cout << ans << '\n';
        return;
    }

    std::sort(pf.begin(), pf.end());
    for(int i = 1; i < N; i++) {
        if(pf[i] == pf[i - 1]) {
            std::cout << 2 << '\n';
            return;
        }
    }

    std::vector<std::vector<int>> G(MAX + 1);
    std::vector<int> all;
    for(int i = 0; i < N; i++) {
        auto [u, v] = pf[i];
        G[u].push_back(v);
        G[v].push_back(u);
        all.push_back(u);
        all.push_back(v);
    }

    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());

    std::vector<int> t(MAX + 1, -1);
    std::vector<int> par(MAX + 1, -1);
    ans = INF;
    int n = sqrt(MAX);
    for(int i = 1; i <= n; i++) {
        if(!G[i].empty()) {
            for(int v : all) {
                t[v] = -1;
            }
            std::queue<int> q;
            q.push(i);
            t[i] = 0;
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                
                for(int nei : G[v]) {
                    if(t[nei] == -1) {
                        t[nei] = t[v] + 1;
                        par[nei] = v;
                        q.push(nei);
                    } else {
                        if(nei != par[v]) {
                            ans = std::min(ans, t[nei] + t[v] + 1);
                        }
                    }
                }
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
