#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = std::accumulate(A.begin(), A.end(), 0);

    int cnt_3 = 0;
    int cnt_1 = 0;
    for(int i = 0; i < N; i++) {
        cnt_3 += A[i] == 3 ? 1 : 0;
        cnt_1 += A[i] == 1 ? 1 : 0;
    }

    if(cnt_3 == 0) {
        std::cout << (sum % 2 == 1 ? N : 0) << '\n';
        return;
    }
    
    if(cnt_1 % 2 == 1) {
        std::cout << (cnt_3 > 2 ? N : N - cnt_3) << '\n';
    } else {
        std::cout << (cnt_3 == 1 ? 1 : N) << '\n';
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
