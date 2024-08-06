#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S, M;
    std::cin >> N >> S >> M;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());

    int pre = 0;
    for(int i = 0; i < N; i++) {
        if(A[i].first - pre >= S) {
            std::cout << "Yes" << '\n';
            return;
        }
        pre = A[i].second;
    }

    if(M - pre >= S) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
