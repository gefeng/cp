#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm> 
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::set<int> s;
    
    s.insert(M);

    int ans = 1;
    std::array<std::pair<int, int>, 3> pos = {};
    pos.fill({-1, -1});
    
    pos[1] = {M, M};
    
    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;

        bool inside = false;
        for(auto& [l, r] : pos) {
            if(l == -1) {
                continue;
            }
            if(P >= l && P <= r) {
                inside = true;
            }
            if(P > r) {
                r = std::min(r + 1, N);
            }
            if(P < l) {
                l = std::max(1, l - 1);
            }
        }

        if(inside) {
            if(pos[0].first == -1) {
                pos[0] = {1, 1};
                pos[2] = {N, N};
                if(pos[1].first == pos[1].second) {
                    ans -= 1;
                    s.erase(pos[1].first);
                    pos[1] = {-1, -1};
                }
            }
        }

        for(auto [l, r] : pos) {
            if(l == -1) {
                continue;
            }
            if(s.find(l) == s.end()) {
                ans += 1;
                s.insert(l);
            }
            if(s.find(r) == s.end()) {
                ans += 1;
                s.insert(r);
            }
        }

        std::cout << ans << " \n"[i == Q - 1];
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
