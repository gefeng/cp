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

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] ^ A[i];
    }

    for(int i = 0; i < N - 1; i++) {
        int lhs = psum[i + 1]; 
        int rhs = psum[N] ^ lhs;
        if(lhs == rhs) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    for(int i = 0; i < N - 2; i++) {
        int lhs = psum[i + 1];
        for(int j = i + 1; j < N - 1; j++) {
            int mid = psum[j + 1] ^ lhs;
            int rhs = psum[N] ^ mid ^ lhs;
            if(lhs == mid && mid == rhs) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
