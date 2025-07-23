#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    int64_t sum = std::accumulate(A.begin(), A.end(), 0LL);

    int a = A[0];
    int b = A[1];
    while(K) {
        int x = (a + b) % 2 == 0 ? (a + b) / 2 : (a + b + 1) / 2;
        if(x == b) {
            sum += static_cast<int64_t>(x) * K;
            break;
        }

        sum += x;
        b = x;
        K -= 1;
    }

    std::cout << sum << '\n';
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
