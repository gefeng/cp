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

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, -1);

    for(int i = 1; i < N - 1; i++) {
        if(A[i] < A[i - 1]) {
            ans[i] = A[i];
        } else {
            ans[i + 1] = A[i];
        }
    }

    ans[0] = A[0];

    for(int i = 1; i < N; i++) {
        if(ans[i] == -1) {
            ans[i] = A[i - 1];
        }
    }

    /*for(int i = 0; i < N - 1; i++) {
        if(std::max(ans[i], ans[i + 1]) != A[i]) {
            std::cout << "NO" << '\n';
        }
    }*/

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
