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
    
    int k = 0;
    std::vector<int> ans(N);
    if(N % 2 == 1) {
        for(int i = 0, j = 2; i < N - 2 && j < N - 1; i += 2, j += 2) {
            ans[i] = j;
        } 

        for(int i = 1, j = 1; i < N - 2; i += 2, j += 2) {
            ans[i] = j;
        }
        
        ans[N - 3] = N - 2;
        ans[N - 2] = N - 1;
        ans[N - 1] = N;

        std::cout << N << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
            if(i % 2 == 0) {
                k &= ans[i];
            } else {
                k |= ans[i];
            }
        }

        assert(k == N);
    } else {
        ans[N - 1] = N;        
        int hb = -1;
        int x = 0;
        
        for(int i = 30; i >= 0; i--) {
            if(N & (1 << i)) {
                hb = i;
                break;
            }
        }
        
        for(int i = hb - 1; i >= 0; i--) {
            if(!(N & (1 << i))) {
                x |= 1 << i; 
            }
        }
        
        int a = -1;
        int b = -1;
        for(int i = 1; i < N; i++) {
            if((i & x) == x) {
                if(a == -1) {
                    a = i;
                } else if(b == -1) {
                    b = i;
                }
            }
        }
        
        if(b == -1) {
            int n = N - 1;
            for(int i = 0, j = 2; i < n - 2 && j < n - 1; i += 2, j += 2) {
                ans[i] = j;
            } 

            for(int i = 1, j = 1; i < n - 2; i += 2, j += 2) {
                ans[i] = j;
            }
            
            ans[n - 3] = n - 2;
            ans[n - 2] = n - 1;
            ans[n - 1] = n;
        } else {
            ans[N - 2] = b;
            ans[N - 3] = a;
            for(int i = 0, j = 1; i < N - 3; i++) {
                while(j == a || j == b || j == N) {
                    j += 1;
                }
                ans[i] = j++;
            }
        }

        int k = 0;
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                k &= ans[i];
            } else {
                k |= ans[i];
            }
        }
        std::cout << k << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
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
