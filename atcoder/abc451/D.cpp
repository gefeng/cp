#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(1e9);

void gen(std::vector<int64_t>& a, std::vector<int64_t>& b, int64_t x, std::vector<int>& all) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        int64_t y = x * b[i] + a[i];
        if(y >= 1 && y <= MAX) {
            all.push_back(y);
            if(y < MAX) {
                gen(a, b, y, all);
            }
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> a;
    std::vector<int64_t> b;
    for(int i = 0; i < 30; i++) {
        a.push_back(1 << i);
        int x = 1 << i;
        int64_t y = 1;
        while(x) {
            y *= 10;
            x /= 10;
        }
        b.push_back(y);
    }

    std::vector<int> all;
    gen(a, b, 0, all);
    std::ranges::sort(all);
    all.erase(std::unique(all.begin(), all.end()), all.end());
    
    std::cout << all[N - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
