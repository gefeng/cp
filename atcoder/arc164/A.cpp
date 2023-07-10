#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;

    if(K > N) {
        std::cout << "No" << '\n';
        return;
    }
    
    int cnt = 0;
    while(N) {
        cnt += N % 3;
        N /= 3;
    }

    if(cnt > K) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << ((K - cnt) % 2 == 0 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
