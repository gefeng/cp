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
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int max_a = 0;
    int max_b = 0;
    for(int i = 0; i < N; i++) {
        max_a = std::max(max_a, A[i]);
        max_b = std::max(max_b, B[i]);
    }

    if(A[N - 1] != max_a && B[N - 1] != max_b) {
        std::cout << "NO" << '\n';
        return;
    }

    if(A[N - 1] == max_a && B[N - 1] == max_b) {
        std::cout << "YES" << '\n';
        return;
    }

    if(A[N - 1] == max_a) {
        std::swap(A, B);
    }

    for(int i = 0; i < N; i++) {
        if(A[i] > A[N - 1] && (A[i] > B[N - 1] || B[i] > A[N - 1])) {
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
