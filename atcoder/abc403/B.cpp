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

    int n = S.size();
    int m = T.size();

    if(n < m) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i <= n - m; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(S[i + j] != T[j] && S[i + j] != '?') {
                cnt += 1; 
            }
        } 

        if(cnt == 0) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
