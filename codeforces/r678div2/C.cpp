#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N, X, P;
    std::cin >> N >> X >> P;
    
    std::vector<int> greater(N, -1);
    int lo = 0;
    int hi = N;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        
        if(mid == P) {
            lo = mid + 1;
        } else if(P < mid) {
            greater[mid] = 1;  
            hi = mid;
        } else {
            greater[mid] = 0;
            lo = mid + 1;
        }
    }
    
    int cnt_1 = 0;
    int cnt_2 = 0;
    int cnt_3 = 0;
    for(int i = 0; i < N; i++) {
        if(greater[i] == 1) {
            cnt_1 += 1;
        } else if(greater[i] == 0) {
            cnt_2 += 1;
        }
    }

    if(cnt_1 > N - X || cnt_2 > X - 1) {
        std::cout << 0 << '\n';
        return;
    }

    cnt_3 = N - cnt_1 - cnt_2 - 1;
    int64_t ans = 1;
    for(int i = 1; i <= cnt_3; i++) {
        ans *= i;
        ans %= MOD;
    }

    for(int i = N - X, j = 0; j < cnt_1; j++, i--) {
        ans *= i;
        ans %= MOD;
    }

    for(int i = X - 1, j = 0; j < cnt_2; j++, i--) {
        ans *= i;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
