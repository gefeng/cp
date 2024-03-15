#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M, L, Q;

    std::cin >> N;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cin >> M;
    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::cin >> L;
    std::vector<int> C(L);
    for(int i = 0; i < L; i++) {
        std::cin >> C[i];
    }

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < L; k++) {
                s.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        std::cout << (s.find(X) == s.end() ? "No" : "Yes") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
