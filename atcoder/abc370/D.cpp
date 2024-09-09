#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int H, W, Q;
    std::cin >> H >> W >> Q;
    
    std::vector<std::set<int>> rows(H);
    std::vector<std::set<int>> cols(W);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            rows[i].insert(j);
        }
    }

    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; j++) {
            cols[i].insert(j);
        }
    }
    
    int ans = H * W;
    for(int i = 0; i < Q; i++) {
        int R, C;
        std::cin >> R >> C;
        R -= 1;
        C -= 1;
        
        if(rows[R].find(C) != rows[R].end()) {
            rows[R].erase(C);
            cols[C].erase(R); 
            ans -= 1;
        } else {
            auto it = rows[R].upper_bound(C);
            int l = -1;
            int r = -1;
            if(it != rows[R].end()) {
                ans -= 1; 
                l = *it;
            }
            if(it != rows[R].begin()) {
                it--;
                ans -= 1;
                r = *it;
            }

            if(l != -1) {
                rows[R].erase(l);
                cols[l].erase(R);
            }
            if(r != -1) {
                rows[R].erase(r);
                cols[r].erase(R);
            }

            int u = -1;
            int d = -1;
            it = cols[C].upper_bound(R);
            if(it != cols[C].end()) {
                ans -= 1;
                d = *it;
            }

            if(it != cols[C].begin()) {
                it--;
                ans -= 1;
                u = *it;
            }
            
            if(u != -1) {
                cols[C].erase(u);
                rows[u].erase(C);
            }
            if(d != -1) {
                cols[C].erase(d);
                rows[d].erase(C);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
