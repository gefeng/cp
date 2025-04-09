#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    int cnt_seg = (N + K - 1) / K;

    std::vector<int> ans(N, 0);
    if(cnt_seg >= M + 1) {
        int k = K;
        int best_k = k;
        int max_mex = 0;
        while(true) {
            cnt_seg = (N + k - 1) / k;
            if(cnt_seg <= M) {
                break;
            }

            if(cnt_seg == M + 1) {
                int rem = N % k; 
                int mex = rem == 0 ? k + 1 : rem + 1;
                if(mex > max_mex) {
                    max_mex = mex;
                    best_k = k;
                }
            } else {
                int mex = k + 1;
                if(mex > max_mex) {
                    max_mex = mex;
                    best_k = k;
                }
            }
            k += 1;
        }

        k = best_k;
        cnt_seg = (N + k - 1) / k;
        
        for(int i = 0; i < cnt_seg; i++) {
            for(int j = 0; j < k; j++) {
                if(i * k + j < N) {
                    ans[i * k + j] = j;
                }
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
