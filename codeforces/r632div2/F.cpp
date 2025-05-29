#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> is_prime(N + 1, 1);
    int cnt_p = 0;
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            cnt_p += 1;
            for(int j = i + i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    std::vector<int> dp(N + 1, 0);
    std::vector<int> freq(N + 1, 0);
    for(int i = N; i >= 2; i--) {
        for(int j = i + i; j <= N; j += i) {
            if(dp[j] == 0) {
                dp[j] = i;
                freq[i] += 1;
            }
        }
    }

    std::vector<int> ans;
    int p = 2;
    while(ans.size() != N - 1) {
        if(ans.size() < cnt_p) {
            ans.push_back(1); 
            continue;
        }

        int cnt = freq[p];
        while(cnt && ans.size() != N - 1) {
            ans.push_back(p);
            cnt -= 1;
        }
        
        p += 1;
    }

    for(int i = 0; i < N - 1; i++) {
        std::cout << ans[i] << " \n"[i == N - 2];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
