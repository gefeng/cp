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
    int N;
    std::cin >> N;

    std::vector<int> ans(N + 1, 0);
    std::iota(ans.begin() + 1, ans.end(), 1);

    std::vector<int> is_prime(N + 1, 1);
    for(int64_t i = N; i >= 2; i--) {
        if(is_prime[i]) {
            std::vector<int> pos;
            pos.push_back(i);
            for(int64_t j = i + i; j <= N; j += i) {
                if(is_prime[j]) {
                    is_prime[j] = 0;
                    pos.push_back(j); 
                }
            }

            int n = pos.size();
            if(n > 1) {
                int pre = ans[pos[n - 1]];
                for(int p = 0; p < n; p++) {
                    int nxt = ans[pos[p]];
                    ans[pos[p]] = pre; 
                    pre = nxt;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
