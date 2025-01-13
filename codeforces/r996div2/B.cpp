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

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    std::vector<int64_t> diff(N + 1, 0);
    int64_t rolling = 0;
    for(int i = 0; i < N; i++) {
        rolling += diff[i];
        int64_t have = A[i].first + rolling; 
        if(have < 0) {
            std::cout << "No" << '\n';
            return;
        }
        if(have < A[i].second) {
            int64_t d = A[i].second - have; 
            A[i].first = A[i].second;
            diff[i + 1] -= d;
            diff[N] += d;
            diff[0] -= d;
            diff[i] += d;
        }
    }

    rolling = 0;
    for(int i = 0; i < N; i++) {
        rolling += diff[i];
        A[i].first += rolling;
        if(A[i].first < 0 || A[i].first < A[i].second) {
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
