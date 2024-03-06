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

    std::string S;
    std::cin >> S;
    
    std::string rs = S;
    std::reverse(rs.begin(), rs.end());
    
    if(S == rs) {
        std::cout << S << '\n';
        return;
    }

    if(S < rs) {
        std::cout << (N % 2 == 0 ? S : S + rs) << '\n';
    } else {
        std::cout << (N % 2 == 0 ? rs + S  : rs) << '\n';
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
