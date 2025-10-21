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
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int rating = A[0];
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> cnt(M, 0);
    for(int i = 0; i < M; i++) {
        if(B[i] <= rating) {
            continue;
        } 
        
        cnt[i] = A.end() - std::lower_bound(A.begin(), A.end(), B[i]);
    }

    std::sort(cnt.begin(), cnt.end());

    std::vector<int> ans(M, 0);
    for(int k = 1; k <= M; k++) {
        int rem = M % k;
        int tot = M - rem;
        int64_t res = 0;
        
        for(int i = 0; i < tot; i += k) {
            res += 1 + cnt[i + k - 1];
        } 

        std::cout << res << " \n"[k == M];
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
