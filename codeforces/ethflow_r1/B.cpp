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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    for(int i = 0; i < N; i++) {
        a[i] -= i + 1;
        if(a[i] <= 0) {
            std::cout << "No" << '\n';
            return;
        }
        a[i] = A[i];
    } 

    for(int i = N - 1; i >= 0; i--) {
        a[i] -= (N - i - 1) * 2;
        if(a[i] <= 0) {
            std::cout << "No" << '\n';
            return;
        }
        a[i] = A[i];
    }

    for(int i = 0; i < N; i++) {
        a[i] -= i * 2;
        if(a[i] <= 0) {
            std::cout << "No" << '\n';
            return;
        }
        a[i] = A[i];
    } 

    for(int i = N - 1; i >= 0; i--) {
        a[i] -= (N - i - 1) * 2;
        if(a[i] <= 0) {
            std::cout << "No" << '\n';
            return;
        }
        a[i] = A[i];
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
