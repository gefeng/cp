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

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int64_t ans = 0;
    if(K % 2 == 1) {
        if(A[0] < B.back()) {
            std::swap(A[0], B[M - 1]);
        } 

        for(int x : A) {
            ans += x;
        } 
    } else {
        if(A[0] < B.back()) {
            std::swap(A[0], B[M - 1]);
            std::sort(A.begin(), A.end());
            std::sort(B.begin(), B.end());
            
            if(B[0] < A.back()) {
                std::swap(B[0], A[N - 1]);
            }

            for(int x : A) {
                ans += x;
            }
        } else {
            std::swap(B[0], A[N - 1]);
            for(int x : A) {
                ans += x;
            }
        }
    }

    std::cout << ans << '\n';
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
