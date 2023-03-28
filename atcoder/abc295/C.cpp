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
        int X;
        std::cin >> X;
        m[X] += 1;
    }

    int ans = 0;
    for(auto& [_, v] : m) {
        ans += v / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
