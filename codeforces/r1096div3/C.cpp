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

    std::vector<int> ans(N, 0);

    int p = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] % 6 == 0) {
            ans[p++] = A[i];
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] % 6 != 0 && A[i] % 2 == 0) {
            ans[p++] = A[i];
        }
    }

    p = N - 1;
    for(int i = 0; i < N; i++) {
        if(A[i] % 6 != 0 && A[i] % 3 == 0) {
            ans[p--] = A[i];
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] % 2 != 0 && A[i] % 3 != 0) {
            ans[p--] = A[i];
        }
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
