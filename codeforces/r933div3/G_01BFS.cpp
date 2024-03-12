#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

constexpr int INF = (int)1e9;

void run_case() {
    int N, M, S, T;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, C;
        std::cin >> U >> V >> C;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, C);
        G[V].emplace_back(U, C);
    }

    std::cin >> S >> T;
    S -= 1;
    T -= 1;

    std::map<std::pair<int, int>, int> best;
    std::deque<std::tuple<int, int, int>> q; // [v, c, d]
    
    int ans = INF;
    q.emplace_back(S, 0, 0);
    while(!q.empty()) {
        auto [v, c, d] = q.front();
        q.pop_front();
        
        if(best.find({v, c}) != best.end() && best[{v, c}] != d) {
            continue;
        }

        if(v == T) {
            ans = std::min(ans, d);
            continue;
        }

        for(auto [nv, nc] : G[v]) {
            int nd = c == nc ? d : d + 1;
            if(best.find({nv, nc}) == best.end() || best[{nv, nc}] > nd) {
                best[{nv, nc}] = nd;
                
                if(nd == d) {
                    q.emplace_front(nv, nc, nd);
                } else {
                    q.emplace_back(nv, nc, nd);
                }
            }
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
