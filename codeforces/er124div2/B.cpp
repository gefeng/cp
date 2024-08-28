#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> ans;
    
    int64_t x = 0;
    int64_t y = 1;
    while(ans.size() < N) {
        if(x + y <= MAX) {
            x += y;
            ans.push_back(x);
            y *= 3;
        } else {
            break;
        }
    }

    if(ans.size() < N) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
