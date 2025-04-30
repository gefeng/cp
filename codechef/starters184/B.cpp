#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> ans(N);
    int64_t cnt_less = 1;
    int64_t cnt_greater = 0;
    int64_t cnt_inv = 0;
    int64_t len = 1;
    
    for(int i = 0; i < N; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            cnt_inv += cnt_less;
            cnt_less += 1;
            cnt_greater += len;
            len += 1;
        } else {
            cnt_inv += cnt_inv + cnt_greater;
            cnt_less *= 2;
            cnt_greater *= 4;
            len *= 2;
        }

        ans[i] = cnt_inv;
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
