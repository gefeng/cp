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

    int64_t ans = 0;
    for(int b = 0; b < 30; b++) {
        int64_t cnt_1 = 0;
        int64_t cnt_0 = 0;
        int64_t tot_set = 0; 
        for(int i = 1; i < N; i++) {
            int64_t n_cnt_1 = 0;
            int64_t n_cnt_0 = 0;
            if(A[i] & (1 << b)) {
                n_cnt_0 = cnt_1;
                n_cnt_1 = cnt_0;
            } else {
                n_cnt_0 = cnt_0;
                n_cnt_1 = cnt_1;
            }
            
            int x = A[i] ^ A[i - 1];
            if(x & (1 << b)) {
                n_cnt_1 += 1;
            } else {
                n_cnt_0 += 1;
            }

            std::swap(cnt_1, n_cnt_1);
            std::swap(cnt_0, n_cnt_0);

            tot_set += cnt_1;
        }

        ans += tot_set * (1 << b);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
