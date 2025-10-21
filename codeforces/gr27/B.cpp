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
    
    if(N == 1 || N == 3) {
        std::cout << -1 << '\n';
        return;
    }

    std::string ans = "";
    if(N % 2 == 0) {
        for(int i = 0; i < N - 2; i++) {
            ans.push_back('3');
        } 
        ans.append("66");
    } else {
        for(int i = 0; i < N - 4; i++) {
            ans.push_back('3');
        }
        ans.append("6366");
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
