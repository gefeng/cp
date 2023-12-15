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
    int A, B, XK, YK, XQ, YQ;
    std::cin >> A >> B >> XK >> YK >> XQ >> YQ;

    int ans = 0;
    std::set<std::pair<int, int>> s;
    for(int dx = -A; dx <= A; dx += 2 * A) {
        for(int dy = -B; dy <= B; dy += 2 * B) {
            int px = XK + dx;
            int py = YK + dy;
            
            if(s.find({px, py}) == s.end() && ((std::abs(px - XQ) == A && std::abs(py - YQ) == B) || (std::abs(px - XQ) == B && std::abs(py - YQ) == A))) {
                ans += 1;
            }

            s.emplace(px, py);
        }
    }

    for(int dx = -B; dx <= B; dx += 2 * B) {
        for(int dy = -A; dy <= A; dy += 2 * A) {
            int px = XK + dx;
            int py = YK + dy;
            if(s.find({px, py}) == s.end() && ((std::abs(px - XQ) == A && std::abs(py - YQ) == B) || (std::abs(px - XQ) == B && std::abs(py - YQ) == A))) {
                ans += 1;
            }
            s.emplace(px, py);
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
