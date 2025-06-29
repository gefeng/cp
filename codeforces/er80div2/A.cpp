#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;

    if(D <= N) {
        std::cout << "YES" << '\n';
        return;
    }
    
    int n = sqrt(D);
    for(int x = 1; x <= n; x++) {
        if((D + x) / (x + 1) + x <= N) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
