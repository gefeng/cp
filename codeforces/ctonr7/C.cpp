#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first;
        B[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());
    std::sort(B.begin(), B.end());

    std::sort(B.begin(), B.begin() + X, std::greater<std::pair<int, int>>());
    std::sort(B.begin() + X, B.end(), std::greater<std::pair<int, int>>());

    for(int i = 0; i < X; i++) {
        if(A[i].first <= B[i].first) {
            std::cout << "No" << '\n';
            return;
        }
    } 

    for(int i = X; i < N; i++) {
        if(A[i].first > B[i].first) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        ans[A[i].second] = B[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
