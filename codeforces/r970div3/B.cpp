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
    
    std::string S;
    std::cin >> S;

    int n = int(std::sqrt(N));
    if(n * n != N) {
        std::cout << "NO" << '\n';
        return;
    } 

    for(int i = 0; i < N; i++) {
        int r = i / n;
        int c = i % n;
        if(r == 0 || c == 0 || r == n - 1 || c == n - 1) {
            if(S[i] != '1') {
                std::cout << "NO" << '\n';
                return;
            }
        } else {
            if(S[i] != '0') {
                std::cout << "NO" << '\n';
                return;
            }
        }
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
