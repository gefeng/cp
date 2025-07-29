#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int Q, D;
    std::cin >> Q >> D;

    std::vector<int> A(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i];
    }

    auto check = [&](int x) {
        while(x) {
            if(x % 10 == D) {
                return true;
            }
            x /= 10;
        } 
        return false;
    };

    for(int i = 0; i < Q; i++) {
        int x = A[i];
        bool ok = false;
        while(true) {
            if(check(x)) {
                ok = true;
                break;
            }
            if(x >= D) {
                x -= D;
            } else {
                break;
            }
        }

        std::cout << (ok ? "Yes" : "No") << '\n';
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
