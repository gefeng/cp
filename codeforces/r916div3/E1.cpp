#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].first;
    }

    for(int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }

    std::array<int64_t, 2> s = {};
    std::sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
                return a.first + a.second > b.first + b.second;
            });

    for(int i = 0, t = 0; i < n; i++, t ^= 1) {
        if(t == 0) {
            s[0] += a[i].first - 1;
        } else {
            s[1] += a[i].second - 1; 
        }
    }

    std::cout << s[0] - s[1] << '\n';
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
