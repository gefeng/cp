#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    std::sort(B.begin(), B.end());

    for(int i = 0; i < M; i++) {
        int j = i;
        int l = B[j];
        int r = B[j];
        while(i + 1 < M && B[i] + 1 == B[i + 1]) {
            i += 1;
            r += 1;
        }

        std::sort(A.begin() + l, A.begin() + r + 2);
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
