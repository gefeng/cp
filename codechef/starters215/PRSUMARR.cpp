#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    if(N <= 3) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> factors;
    int64_t ans = 0;
    for(int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            factors.push_back(i);
            if(N / i != i) {
                factors.push_back(N / i);
            }
            ans += 1;
        }
    }

    if(ans >= 3) {
        std::cout << 3 << '\n';
        return;
    }

    int n = factors.size();
    std::ranges::sort(factors);
    if(n == 2) {
        std::cout << 1 << '\n';
        return;
    }

    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < i; j++) {
            if(factors[i] % factors[j] == 0) {
                ans += 1;
            }
        }
    }

    std::cout << std::min(static_cast<int64_t>(3), ans) << '\n';
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
