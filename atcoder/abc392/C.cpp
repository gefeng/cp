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
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    std::vector<int> bib(N, 0);
    for(int i = 0; i < N; i++) {
        bib[B[i]] = i; 
    }

    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        int who = bib[i];
        int staring = A[who];
        ans[i] = B[staring];

        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
