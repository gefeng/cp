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

    std::vector<int> ans(N, 0);

    std::iota(ans.begin(), ans.end(), 1);

    std::reverse(ans.begin(), ans.begin() + N - 2);
    if(N % 2 == 1) {
        for(int i = N - 3; i > 0; i--) {
            ans[i] = ans[i - 1];
        }
        ans[0] = 1;
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
