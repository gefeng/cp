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
    int ans = -1;
    for(int i = 0, j = 0; i < n || j < m; i++, j++) {
        if(i == n) {
            ans = j;
            break;
        }
        if(j == m) {
            ans = i;
            break;
        }
        if(S[i] != T[j]) {
            ans = i;
            break;
        }
    }

    std::cout << ans + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
