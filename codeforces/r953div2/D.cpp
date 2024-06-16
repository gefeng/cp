#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C;
    std::cin >> N >> C;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> suffix_max(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        suffix_max[i] = A[i];
        if(i + 1 < N) {
            suffix_max[i] = std::max(suffix_max[i + 1], suffix_max[i]); 
        }
    } 

    std::vector<int> ans(N, 0);
    if(A[0] + C < suffix_max[1]) {
        ans[0] = 1;
    }

    int max_v = A[0];
    int64_t sum = A[0];
    for(int i = 1; i < N; i++) {
        int s_max = i + 1 < N ? suffix_max[i + 1] : -1;
        if(A[i] > max_v) {
            if(A[i] >= s_max && A[i] > A[0] + C) {
                ans[i] = 0;
            } else {
                if(A[i] >= s_max) {
                    ans[i] = i;
                } else {
                    ans[i] = i + (sum + A[i] + C < s_max ? 1 : 0); 
                }
            }
        } else {
            ans[i] = i + (sum + A[i] + C < s_max ? 1 : 0);
        }

        max_v = std::max(max_v, A[i]);
        sum += A[i];
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
