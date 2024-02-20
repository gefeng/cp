#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;

    std::vector<int> ans;
    int l = 0;
    int r = N - 1;
    
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == 'L') {
            l += 1;
        } else {
            r -= 1;
        }
    }

    ans.push_back(A[l] % M);
    int64_t p = A[l];
    for(int i = N - 2; i >= 0; i--) {
        if(S[i] == 'L') {
            l -= 1;
            p *= A[l]; 
            p %= M;
        } else {
            r += 1;
            p *= A[r];
            p %= M;
        }

        ans.push_back(p);
    }

    std::reverse(ans.begin(), ans.end());
    
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
