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

    std::string S;
    std::cin >> S;
    
    if(K == 0) {
        std::string rs(S);
        std::reverse(rs.begin(), rs.end());
        std::cout << (S < rs ? "Yes" : "No") << '\n';
        return;
    }

    for(int i = N - 1; i > 0; i--) {
        if(S[0] == S[i]) {
            continue;
        }
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
