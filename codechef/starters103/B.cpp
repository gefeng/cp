#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> save_l(N, INF);
    std::vector<int64_t> save_r(N, INF);
    std::vector<int64_t> ans(N, INF);
    
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            save_l[i] = B[i] - A[i];
        } else {
            if(B[i] >= save_l[i - 1]) {
                save_l[i] = B[i] - A[i];
            } else {
                save_l[i] = save_l[i - 1] - A[i];
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(i == N - 1) {
            save_r[i] = B[i] - A[i];
        } else {
            if(B[i] >= save_r[i + 1]) {
                save_r[i] = B[i] - A[i];
            } else {
                save_r[i] = save_r[i + 1] - A[i];
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            ans[i] = save_r[i];
        } else if(i == N - 1) {
            ans[i] = save_l[i];
        } else {
            if(save_l[i] > save_r[i]) {
                int64_t x = save_l[i] + A[i] - save_l[i - 1];
                ans[i] = save_l[i] + std::max((int64_t)0, save_r[i + 1] - x);
            } else {
                int64_t x = save_r[i] + A[i] - save_r[i + 1];
                ans[i] = save_r[i] + std::max((int64_t)0, save_l[i - 1] - x);
            }
        }
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
