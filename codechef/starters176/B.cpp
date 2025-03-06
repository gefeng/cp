#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M;
    std::cin >> N >> M;

    std::vector<int64_t> ans;
    ans.push_back(N);
    for(int i = 0; i < 60; i++) {
        if(N & (int64_t(1) << i)) {
            continue; 
        }
        int64_t x = (int64_t(1) << i) | N;
        if(x <= M) {
            ans.push_back(x);
        }
    }

    int k = ans.size();
    if(k == 1) {
        std::cout << -1 << '\n';
        return;
    }
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k - 1];
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
