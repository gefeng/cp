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

    std::vector<int> pre_eve(N, -1);
    std::vector<int> cnt_odd(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            pre_eve[i] = i;
        } else {
            pre_eve[i] = i ? pre_eve[i - 1] : -1;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(A[i] % 2 == 0) {
            continue;
        }
        
        cnt_odd[i] = i + 1 < N ? cnt_odd[i + 1] + 1 : 1;
    }

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i] % 2 == 0 ? i + 1 : pre_eve[i] + 1;
    }

    int64_t ans = sum;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 1) { 
            int64_t cand = sum;
            int64_t c = cnt_odd[i];
            cand += c * (i - pre_eve[i]);
            ans = std::max(ans, cand);
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
