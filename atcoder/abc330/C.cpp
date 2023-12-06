#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int64_t D;
    std::cin >> D;

    std::set<int64_t> sq;
    for(int64_t i = 0; i * i <= D; i++) {
        sq.insert(i * i);
    }
    
    int64_t min_d = INF;
    for(int64_t x : sq) {
        auto it = sq.lower_bound(D - x);
        if(it != sq.end()) {
            int64_t d = std::abs(x + *it - D);
            min_d = std::min(min_d, d);
        } 
        if(it != sq.begin()) {
            it--;
            int64_t d = std::abs(x + *it - D);
            min_d = std::min(min_d, d);
        }
    }

    std::cout << min_d << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
