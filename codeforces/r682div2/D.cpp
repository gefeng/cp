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
    
    std::vector<int> A(N);
    int xor_sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        xor_sum ^= A[i];
    }

    if(N % 2 == 0 && xor_sum != 0) {
        std::cout << "No" << '\n';
        return;
    }

    int last = N % 2 == 1 ? N : N - 1;
    std::vector<std::array<int, 3>> ans;
    for(int i = 0; i <= last - 3; i += 2) {
        ans.push_back({i, i + 1, i + 2});
    }

    for(int i = last - 3; i - 2 >= 0; i -= 2) {
        ans.push_back({i, i - 1, i - 2});
    }

    int n = ans.size();
    std::cout << "Yes" << '\n' << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << ' ' << ans[i][2] + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
