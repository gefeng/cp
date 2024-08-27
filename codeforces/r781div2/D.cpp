#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    auto query = [](int a, int b) {
        std::cout << "? " << a << ' ' << b << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int r = 0;
    int ans = 0;
    for(int i = 0; i < 30; i++) {
        int res = query((1 << i) - r, (1 << (i + 1)) + (1 << i) - r); 
        if(res == (1 << (i + 1))) {
            r = (1 << i) + r;
        }
    }

    std::cout << "! " << r << std::endl;
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
