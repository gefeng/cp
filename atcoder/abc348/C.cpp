#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        int D, C;
        std::cin >> D >> C;
        if(m.find(C) == m.end()) {
            m[C] = D;
        } else {
            m[C] = std::min(m[C], D);
        }
    }

    int ans = 0;
    for(auto [_, d] : m) {
        ans = std::max(ans, d);
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
