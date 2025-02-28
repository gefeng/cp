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

    if(N == 1) {
        std::cout << -1 << '\n';
        return;
    }
    
    std::vector<int> ans(N, 0);
    std::iota(ans.begin(), ans.end(), 1);

    // std::swap(ans[0], ans[1]);
    //
    // if(N > 8) {
    //     std::swap(ans[7], ans[8]);
    // }
    // 
    // if(N > 49) {
    //     std::swap(ans[48], ans[49]);
    // }
    
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += ans[i];
        if(int64_t(sqrtl(sum)) * int64_t(sqrtl(sum)) == sum) {
            if(i + 1 == N) {
                std::cout << -1 << '\n';
                return;
            }
            sum += ans[i + 1];
            std::swap(ans[i], ans[i + 1]);
            i += 1;
        }
        assert(int(sqrt(sum)) * int(sqrt(sum)) != sum);
    } 

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
