#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = int64_t(1e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::array<int, 3> T = {};
    for(int i = 0; i < 3; i++) {
        std::cin >> T[i];
    }

    std::vector<std::vector<std::array<int, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W1, W2;
        std::cin >> U >> V >> W1 >> W2;
        U -= 1;
        V -= 1;
        G[U].push_back({V, W1, W2});
        G[V].push_back({U, W1, W2});
    }

    auto cmp = [&](const auto& a, const auto& b) {
        return a[0] > b[0];
    };

    auto check = [&](int st) {
        std::priority_queue<std::array<int64_t, 3>, std::vector<std::array<int64_t, 3>>, decltype(cmp)> pq(cmp);
        std::vector<std::vector<int64_t>> best(N, std::vector<int64_t>(2, INF));
        
        best[0][0] = st;
        pq.push({st, 0, 0});
    
        while(!pq.empty()) {
            std::array<int64_t, 3> cur = pq.top();
            pq.pop();
            int64_t t = cur[0];
            int s = cur[1];
            int v = cur[2];
            
            if(best[v][s] != t) {
                continue;
            }

            for(std::array<int, 3>& nei : G[v]) {
                int nv = nei[0];
                if(s == 0) {
                    int64_t nt = t + nei[1];
                    if((t >= T[1] && t < T[2]) || (t <= T[1] && nt > T[1])) {
                        nt = t + nei[2];
                        if(best[nv][1] > nt) {
                            best[nv][1] = nt;
                            pq.push({nt, 1, nv});
                        }
                        if(best[nv][0] > T[2] + nei[1]) {
                            best[nv][0] = T[2] + nei[1];
                            pq.push({T[2] + nei[1], 0, nv});
                        }
                    } else {
                        if(best[nv][s] > nt) {
                            best[nv][s] = nt;
                            pq.push({nt, s, nv});
                        }
                    }
                } else {
                    int64_t nt = t + nei[2];
                    if(t >= T[2]) {
                        nt = t + nei[1];
                        if(best[nv][0] > nt) {
                            best[nv][0] = nt;
                            pq.push({nt, 0, nv});
                        }
                    } else {
                        if(best[nv][s] > nt) {
                            best[nv][s] = nt;
                            pq.push({nt, s, nv});
                        }
                        if(best[nv][0] > T[2] + nei[1]) {
                            best[nv][0] = T[2] + nei[1];
                            pq.push({T[2] + nei[1], 0, nv});
                        }
                    }
                } 
            }
        }

        return std::min(best[N - 1][0], best[N - 1][1]) <= T[0];
    };
    
    int lo = 0;
    int hi = int(1e9);
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
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
