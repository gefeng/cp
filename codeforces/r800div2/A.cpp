#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    std::string ans = "";
    if(A >= B) {
        for(int i = 0; i < std::min(A, B); i++) {
            ans.append("01");
        }
        for(int i = 0; i < A - B; i++) {
            ans.push_back('0');
        }
    } else {
        for(int i = 0; i < std::min(A, B); i++) {
            ans.append("10");
        }
        for(int i = 0; i < B - A; i++) {
            ans.push_back('1');
        }
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
