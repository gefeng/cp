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

    std::vector<std::vector<int>> psum(30, std::vector<int>(N + 1, 0));
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < N; j++) {
            psum[i][j + 1] = psum[i][j] + ((A[j] & (1 << i)) ? 1 : 0);
        }
    }

    int Q;
    std::cin >> Q;
    std::vector<int> ans(Q);
    for(int i = 0; i < Q; i++) {
        int L, K;
        std::cin >> L >> K;
        L -= 1;
        
        int lo = L;
        int hi = N - 1;
        int res = -1; 
        while(lo <= hi) {
            int r = (lo + hi) >> 1;
            
            bool ok = true;
            for(int b = 29; b >= 0; b--) {
                bool one = psum[b][r + 1] - psum[b][L] == r - L + 1;
                
                if(one && (K & (1 << b)) == 0) {
                    ok = true;
                    break;
                }
                
                if(!one && (K & (1 << b)) != 0) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                res = r;
                lo = r + 1;
            } else {
                hi = r - 1;
            }
        }

        ans[i] = res;
    }

    for(int i = 0; i < Q; i++) {
        std::cout << (ans[i] == -1 ? ans[i] : ans[i] + 1)  << " \n"[i == Q - 1];
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
