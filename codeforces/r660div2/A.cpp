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

    if(N <= 30) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
    
    std::array<int, 4> ans = {6, 10, 14, 0};
   
    if(N == 36 || N == 40 || N == 44) {
        ans[2] = 15;
    }

    ans[3] = N - (ans[0] + ans[1] + ans[2]);
    
    for(int i = 0; i < 4; i++) {
        std::cout << ans[i] << " \n"[i == 3];
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
