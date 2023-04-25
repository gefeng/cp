#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N % 2 == 1) {
        std::cout << "YES" << '\n';
        return;
    }

    LL sum_eve = 0LL;
    LL sum_odd = 0LL;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            sum_eve += A[i];
        } else {
            sum_odd += A[i];
        }
    }

    std::cout << (sum_eve <= sum_odd ? "YES" : "NO") << '\n';
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
