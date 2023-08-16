#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int t = 0;
    if(C & 1) {
        t = 1;
    }
    
    if(t == 0) {
        std::cout << (A > B ? "First" : "Second") << '\n';
    } else {
        std::cout << (B > A ? "Second" : "First") << '\n';
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
