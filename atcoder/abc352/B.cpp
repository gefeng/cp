#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> ans;
    int n = S.size();
    int m = T.size();
    
    for(int i = 0, j = 0; i < n && j < m; j++) {
        if(S[i] == T[j]) {
            ans.push_back(j);
            i += 1;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
