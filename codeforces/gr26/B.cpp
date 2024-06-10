#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X;
    std::cin >> X;

    std::vector<int> digits;
    while(X) {
        digits.push_back(X % 10);
        X /= 10;
    }

    std::reverse(digits.begin(), digits.end());
    
    if(digits[0] != 1) {
        std::cout << "NO" << '\n';
        return;
    }

    int c = 0;
    for(int i = digits.size() - 1; i > 0; i--) {
        bool ok = false;
        for(int d1 = 5; d1 <= 9; d1++) {
            int d2 = digits[i] + 10 - d1 - c;
            if(d2 >= 5 && d2 <= 9) {
                ok = true;
                break;
            }
        }

        if(!ok) {
            std::cout << "NO" << '\n';
            return;
        }
        c = 1;
    }

    std::cout << "YES" << '\n';
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
