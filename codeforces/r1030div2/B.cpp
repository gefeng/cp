#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int>> ans;
    
    for(int i = 0; i < N; i++) {
        ans.emplace_back(i, 0, i);
        if(i < N - 1) {
            ans.emplace_back(i, i + 1, N - 1);
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        auto [idx, l, r] = ans[i];
        std::cout << idx + 1 << ' ' << l + 1 << ' ' << r + 1 << '\n';
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
