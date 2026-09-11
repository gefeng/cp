#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(1e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> ans(N, 1);
    
    bool exist = false;
    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            ans[i] = MAX;
            exist = true;
        }
    }

    if(!exist) {
        std::cout << "No" << '\n';
        return;
    }
    
    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
