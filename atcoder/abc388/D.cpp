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

    std::vector<int64_t> diff(N + 1, 0);
    std::vector<int64_t> ans(N, 0);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += diff[i];
        ans[i] = sum + A[i];
        
        if(ans[i]) {
            int64_t l = i + 1;
            int64_t r = std::min(int64_t(N) - 1, i + ans[i]);
            diff[l] += 1;
            diff[r + 1] -= 1;
            ans[i] -= r - l + 1; 
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
