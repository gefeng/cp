#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int min_v = INF;
    int p = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] < min_v) {
            min_v = A[i];
            p = i;
        }
    }

    for(int i = p + 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << p << '\n';
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
