#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int a = 0;
    for(int i = 0; i < n; i++) {
        a = a * 10 + S[i] - '0';
        if(i + 1 < n && S[i + 1] != '0') {
            int b = 0;
            for(int j = i + 1; j < n; j++) {
                b = b * 10 + S[j] - '0';
            }
            if(b > a) {
                std::cout << a << ' ' << b << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
