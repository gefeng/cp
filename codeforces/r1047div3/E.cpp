#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    auto get_mex = [&]() {
        int mex = 0;
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i += 1;
            }
            if(A[j] == mex) {
                mex += 1;
            } else {
                break;
            }
        }
        return mex;
    };

    auto is_type1 = [&]() {
        for(int i = 0; i < N; i++) {
            if(A[i] != i) {
                return false;
            }
        }
        return true;
    };

    auto is_type2 = [&]() {
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i += 1;
            }
            if(A[j] == j && i - j == 1) {
                continue;
            }
            
            if(A[j] != j || i != N) {
                return false;
            }
            break;
        } 
        return true;
    };
    
    int64_t ans = 0;
    while(K) {
        K -= 1;
        int mex = get_mex();
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[j] == A[i]) {
                i += 1;
            }
            if(A[j] < mex && i - j == 1) {
                continue;
            }
            for(int k = j; k < i; k++) {
                A[k] = mex;
            }
        }

        if(is_type1()) {
            ans = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
            std::cout << ans << '\n';
            return;
        }

        if(is_type2()) {
            ans = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
            if(K % 2 == 1) {
                int p = N - 1;
                while(p >= 0 && A[p] == A.back()) {
                    p -= 1;
                }
                ans += static_cast<int64_t>(N - 1 - p);
            }
            std::cout << ans << '\n';
            return;
        }
    }

    ans = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
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
