#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t solve1(std::vector<int>& d, int i, int c) {
    if(i == d.size()) {
        return c == 0 ? 1 : 0;
    }
    
    int64_t res = 0;
    int x = (d[i] - c + 10) % 10;
    res += solve1(d, i + 1, 0) * (x + 1);
    res += solve1(d, i + 1, 1) * (9 - x);
    return res;
}

int64_t solve2(std::vector<int>& d, int i, int c) {
    if(i == d.size()) {
        return c == 0 ? 1 : 0;
    }
    
    int64_t res = 0;
    int x = (d[i] - c + 10) % 10;
    res += solve1(d, i + 1, 0) * (x + 1);
    res += solve1(d, i + 1, 1) * (9 - x);
    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    int x = 0;
    int y = 0;
    int base_x = 1;
    int base_y = 1;
    int t = 0;
    while(N) {
        int d = N % 10;
        if(t == 0) {
            x += d * base_x;
            base_x *= 10;
        } else {
            y += d * base_y;
            base_y *= 10;
        }
        N /= 10;
        t ^= 1;
    }

    auto count = [](int x) {
        if(x == 0) {
            return 1;
        }
        return x + 1;
    };

    int64_t a = count(x);
    int64_t b = count(y);

    std::cout << a * b - 2 << '\n';
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
