#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S;
    std::cin >> N >> S;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int pre = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] - pre > S) {
            std::cout << "No" << '\n';
            return;
        }
        pre = A[i];
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
