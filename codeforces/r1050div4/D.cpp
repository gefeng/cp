#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> odd;
    for(int x : A) {
        if(x % 2 == 1) {
            odd.push_back(x);
        }
    }
    if(odd.size() == 0) {
        std::cout << 0 << '\n';
        return;
    }

    std::ranges::sort(odd);
    int64_t ans = 0;

    int m = odd.size() / 2;
    for(int i = odd.size() - 1; i >= m; i--) {
        ans += odd[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            ans += A[i];
        }
    }

    std::cout << ans << '\n';
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
