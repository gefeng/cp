#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N == 1) {
        if(K != 1) {
            std::cout << "No" << '\n';
        } else {
            std::cout << "Yes" << '\n';
            std::cout << "1 1" << '\n';
        }
        return;
    }

    if(N == 2) {
        if(K == 2) {
            std::cout << "Yes" << '\n';
            std::cout << "1 1 2 2" << '\n';
        } else if(K == 3) {
            std::cout << "Yes" << '\n';
            std::cout << "1 2 1 2" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
        return;
    }

    if(K < N || K > (N - 2) * 2 + 3) {
        std::cout << "No" << '\n';
        return;
    }
    
    int n = N;
    while(n >= 1) {
        int k = K - (N - n);
        int lb = n;
        int ub = (n - 2) * 2 + 3;
        if(n == 2) {
            ub = 3;
        }
        if(n == 1) {
            ub = 1;
        }
        if(k == lb) {
            std::cout << "Yes" << '\n';
            for(int i = 0; i < N; i++) {
                std::cout << i + 1 << ' ' << i + 1 << " \n"[i == N - 1];
            } 
            return;
        }
        if(k == ub) {
            std::cout << "Yes" << '\n';
            std::vector<int> ans(N * 2);
            if(n == 2) {
                for(int i = 0; i < 2; i++) {
                    ans[i] = i + 1;
                    ans[i + 2] = i + 1;
                }
            } else {
                for(int i = 0; i < 2; i++) {
                    ans[i] = i + 1;
                }
                
                for(int i = 2, j = 3; i < n * 2 && j <= n; i += 2, j++) {
                    ans[i] = j;
                }
                for(int i = 3, j = 1; i < n * 2 && j <= n - 2; i += 2, j++) {
                    ans[i] = j;
                }

                ans[n * 2 - 1] = n;
                ans[n * 2 - 2] = n - 1;
            }
            
            for(int i = n; i < N; i++) {
                ans[i * 2] = i + 1;
                ans[i * 2 + 1] = i + 1;
            }
            for(int i = 0; i < N * 2; i++) {
                std::cout << ans[i] << " \n"[i == N * 2 - 1];
            }
            return;
        }

        n -= 1;
    }

    assert(0 != 0);
    std::cout << "No" << '\n';
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
