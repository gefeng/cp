#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX_T = 2000;
constexpr int64_t MOD = int64_t(16777216);

void run_case() {
    std::vector<int64_t> A;
    for(std::string S; std::getline(std::cin, S); ) {
        A.push_back(stoi(S));
    }

    std::cout << A.size() << '\n';

    auto gen = [](int64_t x) {
        x ^= (x * 64);
        x %= MOD;     
        x ^= x / 32;
        x %= MOD;
        x ^= x * 2048;
        x %= MOD;
        return x;
    }; 

    int64_t ans = 0;
    for(int64_t x : A) {
        for(int i = 0; i < MAX_T; i++) {
            x = gen(x);
        }
        ans += x;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
