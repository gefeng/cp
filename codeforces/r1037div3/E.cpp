#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

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

    for(int i = 1; i < N; i++) {
        if(A[i] > A[i - 1] || A[i - 1] % A[i] != 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    for(int i = N - 2; i >= 0; i--) {
        if(B[i] > B[i + 1] || B[i + 1] % B[i] != 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    if(A.back() != B[0]) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i < N - 1; i++) {
        int x = A[i];
        int y = B[i + 1];
        if(gcd(x, y) != B[0]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
