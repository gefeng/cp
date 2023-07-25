#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(A[0] == A.back()) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == A[0]) {
                cnt += 1;
            } 
        }

        std::cout << (cnt >= K ? "YES" : "NO") << '\n';
    } else {
        int p = 0;
        int cnt = 0;
        while(p < N && cnt < K) {
            if(A[p] == A[0]) {
                cnt += 1;
            }
            p += 1;
        }

        if(cnt < K) {
            std::cout << "NO" << '\n';
            return;
        }

        cnt = 0;
        while(p < N && cnt < K) {
            if(A[p] == A.back()) {
                cnt += 1;
            }
            p += 1;
        }

        if(cnt < K) {
            std::cout << "NO" << '\n';
            return;
        }

        std::cout << "YES" << '\n';
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
