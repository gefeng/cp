#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = (int64_t)2e18;

int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int64_t a, int64_t b, int64_t c, int64_t &x0, int64_t &y0, int64_t &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void run_case() {
    int N, M, H;
    std::cin >> N >> M >> H;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<std::array<int64_t, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        
        int64_t x = 0;
        int64_t y = 0;
        int64_t g = 0;
        bool res = find_any_solution((B[U] - B[V] + H) % H, H, (A[V] - A[U] + H) % H, x, y, g);
        
        if(res) {
            G[U].push_back({V, x, g});
            G[V].push_back({U, x, g});
        }
    }

    std::vector<int64_t> best(N, INF);
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
    
    pq.emplace(0, 0);
    best[0] = 0;

    while(!pq.empty()) {
        auto [s, v] = pq.top();
        pq.pop();

        if(best[v] != s) {
            continue;
        }

        for(auto& nei : G[v]) {
            int nv = nei[0];
            int64_t x0 = nei[1];
            int64_t g = nei[2];
            
            int64_t k = s - x0 >= 0 ? (s - x0 + H / g - 1) / (H / g) : (s - x0) / (H / g);
            int64_t ns = (x0 + k * (H / g)) + 1;

            if(best[nv] > ns) {
                best[nv] = ns;
                pq.emplace(ns, nv);
            }
        }
    }

    std::cout << (best[N - 1] == INF ? -1 : best[N - 1]) << '\n';
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
