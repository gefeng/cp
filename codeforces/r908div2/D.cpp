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

    std::sort(B.begin(), B.end(), std::greater<int>());

    std::vector<int> ans(N + M);
    int p = N + M - 1;
    for(int i = N - 1, j = M - 1; i >= 0 || j >= 0; ) {
        if(i < 0) {
            ans[p--] = B[j--];
        } else if(j < 0) {
            ans[p--] = A[i--];
        } else {
            if(A[i] >= B[j]) {
                ans[p--] = B[j--]; 
            } else {
                ans[p--] = A[i--];
            }
        }
    } 

    for(int i = 0; i < N + M; i++) {
        std::cout << ans[i] << " \n"[i == N + M - 1];
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
