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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = A[0];
    for(int i = 1; i < N; i++) {
        sum &= A[i];
    }

    if(sum) {
        std::cout << 1 << '\n';
        return;
    }

    std::array<int, 31> cnt = {};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 30; j++) {
            if(A[i] & (1 << j)) {
                cnt[j] += 1;
            }
        }
    }

    int64_t cur = ((int64_t)1 << 31) - 1;
    int ans = 1;
    for(int i = 0; i < N; i++) {
        cur &= A[i];
        
        for(int j = 0; j <= 30; j++) {
            if(A[i] & (1 << j)) {
                cnt[j] -= 1;
            }
        }
        
        if(cur == sum) {
            for(int j = 0; j <= 30; j++) {
                if((sum & (1 << j)) == 0 && cnt[j] == N - i - 1) {
                    std::cout << ans << '\n';
                    return;
                }
            } 

            ans += 1;
            cur = ((int64_t)1 << 31) - 1;
        }
    }

    std::cout << ans << '\n';
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
