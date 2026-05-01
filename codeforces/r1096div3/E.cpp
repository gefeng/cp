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

    int min_h = N + 1;
    int64_t sum = 0;
    for(int i = N - 1; i >= 0; i--) {
        sum += std::max(0, A[i] - min_h);
        min_h = std::min(min_h, A[i]);
    }

    int64_t ans = sum;
    std::vector<int> stk;
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] >= A[i]) {
            stk.pop_back();
        }
    
        int pre = stk.empty() ? -1 : stk.back();
        ans = std::max(ans, sum + i - pre - 1);
        
        stk.push_back(i);
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
