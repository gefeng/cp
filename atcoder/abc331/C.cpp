#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e6;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> freq(MAX + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }

    std::vector<int64_t> psum(MAX + 2, 0);
    for(int i = 0; i <= MAX; i++) {
        psum[i + 1] = psum[i] + (int64_t)i * freq[i];
    }

    for(int i = 0; i < N; i++) {
        int64_t res = 0;
        if(A[i] == MAX) {
            res = 0; 
        } else {
            res = psum[MAX + 1] - psum[A[i] + 1];
        }

        std::cout << res << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
