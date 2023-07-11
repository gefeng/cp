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

    std::sort(A.begin(), A.end());

    std::vector<int> ans(N);

    int j = N - 1;
    for(int i = 1; i < N; i += 2) {
        ans[i] = A[j--];
    }
    
    for(int i = 0; i < N; i += 2) {
        ans[i] = A[j--];
    }

    for(int i = 1; i < N; i += 2) {
        if(ans[i] <= ans[i - 1] || ans[i] <= ans[i + 1]) {
            std::cout << "No" << '\n'; 
            return;
        } 
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
