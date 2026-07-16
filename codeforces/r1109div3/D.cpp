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
    std::vector<int> flippable(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        int X;
        std::cin >> X;
        X--;
        flippable[X] = 1;
    }

    int64_t a = 0;
    int64_t b = 0;
    
    for(int i = 0; i < N; i++) {
        if(flippable[i]) {
            int64_t na = a + A[i];
            int64_t nb = b - A[i];
            na = std::max(na, b - A[i]);
            nb = std::max(nb, a + A[i]);
            a = na;
            b = nb;
        } else {
            a += A[i];
            b -= A[i];
        }
    }

    if(flippable[N - 1]) {
        std::cout << std::max(a, b) << '\n';
    } else {
        std::cout << a << '\n';
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
