#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<int> B(N);
    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    if(B[0] != C[0]) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 1; i < N; i++) {
        if(B[i] < B[i - 1] || C[i] > C[i - 1]) {
            std::cout << "No" << '\n';
            return;
        }
        if(B[i] != B[i - 1] && C[i] != C[i - 1]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::vector<int> ans(N, -1);
    ans[0] = B[0];
    int max_v = B[0];
    int min_v = C[0];
    int pre_min = 1;
    int pre_max = 1;
    
    for(int i = 1; i < N; i++) {
        int j = i;
        while(i < N && B[i] == B[i - 1] && C[i] == C[i - 1]) {
            i += 1;
        }
        
        if(i == N) {
            for(int k = j; k < i; k++) {
                ans[k] = pre_min ? min_v : max_v;
            }
        } else {
            if(B[i] > B[i - 1]) {
                if(pre_max) {
                    if(B[i] - max_v > D) {
                        std::cout << "No" << '\n';
                        return;
                    }

                    for(int k = j; k < i; k++) {
                        ans[k] = max_v;
                    }
                } else {
                    for(int k = j, x = std::min(min_v + D, max_v); k < i; k++, x = std::min(x + D, max_v)) {
                        ans[k] = x; 
                    }
                    if(B[i] - ans[i - 1] > D) {
                        std::cout << "No" << '\n';
                        return;
                    }
                }
                ans[i] = B[i];
                max_v = B[i];
                pre_max = 1;
                pre_min = 0;
            } else {
                if(pre_min) {
                    if(min_v - C[i] > D) {
                        std::cout << "No" << '\n';
                        return;
                    }

                    for(int k = j; k < i; k++) {
                        ans[k] = min_v;
                    }
                } else {
                    for(int k = j, x = std::max(max_v - D, min_v); k < i; k++, x = std::max(x - D, min_v)) {
                        ans[k] = x; 
                    }
                    if(ans[i - 1] - C[i] > D) {
                        std::cout << "No" << '\n';
                        return;
                    }
                }
                ans[i] = C[i];
                min_v = C[i];
                pre_max = 0;
                pre_min = 1;
            }
        }
    }
    
    std::cout << "Yes" << '\n';
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
