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

    if((N / 2) % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int64_t> ans(N, 0);
    int64_t sum = 0;
    for(int i = 0, j = 2; i < N / 2; i++, j += 2) {
        ans[i] = j;
        sum += j;
    }

    for(int i = N / 2, j = 1; i < N - 1; i++, j += 2) {
        ans[i] = j;
        sum -= j;
    }

    ans[N - 1] = sum;
    
    std::cout << "YES" << '\n';
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
