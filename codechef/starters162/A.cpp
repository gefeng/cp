#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    if(K == 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N);
    std::iota(ans.begin(), ans.end(), 1);
    
    for(int i = 0; i < N; i += K) {
        if(i + K <= N) {
            std::reverse(ans.begin() + i, ans.begin() + i + K); 
            std::reverse(ans.begin() + i + 1, ans.begin() + i + K);
        } else {
            std::reverse(ans.begin() + i, ans.end()); 
            std::reverse(ans.begin() + i + 1, ans.end());
        }
    }

    if(ans.back() % K == N % K) {
        for(int i = 0; i < N - 1; i++) {
            if(ans[i] % K != N % K && ans.back() % K != (i + 1) % K) {
                std::swap(ans[i], ans.back());
                break;
            }
        }
    }

    if(ans.back() % K == N % K) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
