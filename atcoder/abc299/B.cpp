#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, T;
    std::cin >> N >> T;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    bool has_t = false;
    for(int i = 0; i < N; i++) {
        if(A[i] == T) {
            has_t = true;
        }
    }

    int ans = 0;
    int max_r = 0;
    if(has_t) {
        for(int i = 0; i < N; i++) {
            if(A[i] == T) {
                if(max_r < B[i]) {
                    max_r = B[i];
                    ans = i + 1;
                }
            }
        }
    } else {
        ans = 1;
        max_r = B[0];
        for(int i = 1; i < N; i++) {
            if(A[i] == A[0]) {
                if(max_r < B[i]) {
                    max_r = B[i];
                    ans = i + 1;
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
