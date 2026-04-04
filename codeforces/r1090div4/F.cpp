#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    if(X > Y) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<std::pair<int, int>> E;
    int n = X + Y;
    int now = 2;
    int cnt_eve = (X + Y) % 2 == 0 ? X - 1 : X;
    int cnt_odd = (X + Y) % 2 == 1 ? Y - 1 : Y;
    for(int i = 0; i < cnt_eve; i++) {
        E.emplace_back(1, now);
        E.emplace_back(now, now + 1);
        now += 2;
        cnt_odd--;
    }

    for(int i = 0; i < cnt_odd; i++) {
        E.emplace_back(1, now++);
    }

    if(E.size() != n - 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    for(auto [u, v] : E) {
        std::cout << u << ' ' << v << '\n';
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
