#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = i + 1;
    }

    if(X == 1) {
        for(int i = 0; i < N; i++) {
            std::cout << i + 1 << " \n"[i == N - 1];
        }
        return;
    }
    
    if(X == N) {
        for(int i = 0; i < N; i++) {
            std::cout << N - i << " \n"[i == N - 1];
        }
        return;
    }

    if(N % 2 == 1 && X == (N + 1) / 2) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N);
    if(N % 2 == 1) {
        ans[N / 2] = N / 2 + 1;
        if(X <= N / 2) {
            int cur = X;
            int p = 0;
            while(cur >= 1) {
                ans[p++] = cur--;
            }

            cur = X + 1;
            while(cur <= N / 2) {
                ans[p++] = cur++;
            }
        } else {
            int cur = X;
            int p = 0;
            while(cur <= N) {
                ans[p++] = cur++;
            }
            
            cur = X - 1;
            while(cur > (N + 1) / 2) {
                ans[p++] = cur--; 
            }
        }
    } else {
        if(X <= N / 2) {
            int cur = X;
            int p = 0;
            while(cur <= N / 2) {
                ans[p++] = cur++;
            }

            cur = 1;
            p = N / 2 - 1;
            while(cur < X) {
                ans[p--] = cur++;
            }
        } else {
            int cur = X;
            int p = 0;
            while(cur > N / 2) {
                ans[p++] = cur--;
            }
            
            cur = N;
            p = N / 2 - 1;
            while(cur > X) {
                ans[p--] = cur--;
            }
        }
    }

    for(int i = N / 2; i < N; i++) {
        ans[i] = N - ans[N - 1 - i] + 1;
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
