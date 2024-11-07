#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ans;
    for(int i = 1; i <= K / 2; i++) {
        ans.push_back(K - i);
    }
    
    for(int i = K + 1; i <= N; i++) {
        ans.push_back(i);
    }

    int m = ans.size();
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        std::cout << ans[i] << " \n"[i == m - 1];
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
