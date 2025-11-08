#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, N;
    std::cin >> X >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> attached(N, 0);
    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;
        P -= 1;

        if(attached[P]) {
            X -= A[P];
        } else {
            X += A[P];
        }
        attached[P] ^= 1;

        std::cout << X << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
