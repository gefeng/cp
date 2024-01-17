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
    int N;
    std::cin >> N;

    std::set<std::array<int, 3>> s;
    for(int x = 0; x <= N; x++) {
        for(int y = 0; y <= N; y++) {
            for(int z = 0; z <= N; z++) {
                if(x + y + z <= N) {
                    s.insert({x, y, z});
                }
            }
        }
    }

    for(auto& v : s) {
        std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
