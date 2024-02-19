#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)2e5;

std::vector<int64_t> psum(MAX + 1, 0);

void run_case() {
    int N;
    std::cin >> N;

    std::cout << psum[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    auto get_sum = [](int x) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };

    for(int i = 1; i <= MAX; i++) {
        psum[i] = psum[i - 1] + get_sum(i);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
