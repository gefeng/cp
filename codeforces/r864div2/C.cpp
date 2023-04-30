#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    auto q = [](int r, int c) {
        std::string s = "? " + std::to_string(r) + " " + std::to_string(c);
        std::cout << s << std::endl;

        int res;
        std::cin >> res;
        
        return res;
    };

    int d1 = q(1, 1);
    int d2 = q(1, std::min(M, d1 + 1)); 
    int d3 = q(std::min(N, d1 + 1), 1);

    int ans_r = 0;
    int ans_c = 0;
    if(d2 == d3) {
        ans_r = d1 + 1;
        ans_c = d1 + 1;
    } else if(d2 < d3) {
        ans_r = d2 + 1;
        ans_c = d1 + 1;
    } else {
        ans_r = d1 + 1;
        ans_c = d3 + 1;
    }

    std::cout << "! " << ans_r << ' ' << ans_c << std::endl;
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
