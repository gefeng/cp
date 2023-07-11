#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1000;

void run_case() {
    int64_t N;
    std::cin >> N;

    for(int k = 2; k <= MAX; k++) {
        int64_t sum = 1 + k + k * k;
        int64_t x = k * k * k;
        while(x + sum <= N) {
            sum += x;
            x *= k;
        }

        if(sum == N) {
            std::cout << "YES" << '\n';
            return;
        }
    } 

    std::cout << "NO" << '\n';
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
