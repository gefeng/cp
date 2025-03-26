#include <iostream>
#include <utility> 
#include <cassert> 
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <tuple>

constexpr int64_t INF = int64_t(2e18);

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M, P, Q;
    std::cin >> N >> M >> P >> Q;

    int64_t ans = INF;
    
    std::vector<int> d_n;
    std::vector<int> d_m;
    for(int f = 1; f * f <= N; f++) {
        if(N % f == 0) {
            d_n.push_back(f);
            if(N / f != f) {
                d_n.push_back(N / f);
            }
        }
    }

    for(int f = 1; f * f <= M; f++) {
        if(M % f == 0) {
            d_m.push_back(f);
            if(M / f != f) {
                d_m.push_back(M / f);
            }
        }
    }

    std::set<int> s_x(d_n.begin(), d_n.end());
    std::set<int> s_y(d_m.begin(), d_m.end());
    
    auto dijk = [&](int sx, int sy, int l_x, int r_x, int l_y, int r_y) {
        std::map<std::pair<int, int>, int64_t> best;
        
        auto cmp = [](const auto& x, const auto& y) {
            return std::get<2>(x) > std::get<2>(y);
        };
        std::priority_queue<std::tuple<int, int, int64_t>, std::vector<std::tuple<int, int, int64_t>>, decltype(cmp)> pq(cmp);

        best[{sx, sy}] = int64_t(std::max(sx, N / sx)) * std::max(sy, M / sy);
        pq.emplace(sx, sy, best[{sx, sy}]);

        while(!pq.empty()) {
            auto [x, y, c] = pq.top();
            pq.pop();
            if(c != best[{x, y}]) {
                continue;
            }

            for(int d = 0; d < 4; d++) {
                int nx = x + DR[d];
                int ny = y + DC[d];
                if(nx >= l_x && ny >= l_y && nx <= r_x && ny <= r_y) {
                    int64_t nc = int64_t(std::max(nx, N / nx)) * std::max(ny, M / ny) + c;
                    if(best.find({nx, ny}) == best.end() || best[{nx, ny}] > nc) {
                        best[{nx, ny}] = nc;
                        pq.emplace(nx, ny, nc);
                    }
                }
            }
        }
        
        return best;
    };

    int l_x = 1; 
    int r_x = 1;
    int l_y = 1;
    int r_y = 1;
    while(r_x <= N && s_x.find(r_x) != s_x.end()) {
        r_x += 1;
    }

    while(r_y <= M && s_y.find(r_y) != s_y.end()) {
        r_y += 1;
    }


    std::map<std::pair<int, int>, int64_t> best_1 = dijk(1, 1, 1, r_x - 1, 1, r_y - 1);

    int64_t leave_1 = INF;
    for(int x = 1; x < r_x; x++) {
        for(int y = 1; y < r_y; y++) {
            if(x == r_x - 1 || y == r_y - 1) {
                leave_1 = std::min(leave_1, best_1[{x, y}]);
            }
        }
    }

    if(s_x.find(P) == s_x.end() || s_y.find(Q) == s_y.end()) {
        ans = leave_1;
        std::cout << ans << '\n';
        return;
    }
    
    if(P >= l_x && P < r_x && Q >= l_y && Q < r_y) {
        ans = std::min(ans, best_1[{P, Q}]);
    }
    
    l_x = P;
    r_x = P;
    l_y = Q;
    r_y = Q;
    while(l_x >= 1 && s_x.find(l_x) != s_x.end()) {
        l_x -= 1;
    }
    while(r_x <= N && s_x.find(r_x) != s_x.end()) {
        r_x += 1;
    }
    while(l_y >= 1 && s_y.find(l_y) != s_y.end()) {
        l_y -= 1;
    }
    while(r_y <= M && s_y.find(r_y) != s_y.end()) {
        r_y += 1;
    }

    std::map<std::pair<int, int>, int64_t> best_2 = dijk(P, Q, l_x + 1, r_x - 1, l_y + 1, r_y - 1);
    int64_t leave_2 = INF;
    for(int x = l_x + 1; x < r_x; x++) {
        for(int y = l_y + 1; y < r_y; y++) {
            if((l_x + 1 != 1 && x == l_x + 1) || x == r_x - 1 || (l_y + 1 != 1 && y == l_y + 1) || y == r_y - 1) {
                leave_2 = std::min(leave_2, best_2[{x, y}]);
            }
        }
    }

    ans = std::min(ans, leave_1 + leave_2);

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
