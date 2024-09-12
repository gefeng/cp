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

    char C;
    std::cin >> C;
    
    std::string S;
    std::cin >> S;

    bool good = true;
    for(int i = 0; i < N; i++) {
        if(S[i] != C) {
            good = false; 
            break;
        }
    }

    if(good) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> bad(N + 1, 0);
    for(int i = 0; i < N; i++) {
        if(S[i] != C) {
            bad[i + 1] = 1;
        }
    }

    for(int i = N; i > 1; i--) {
        bool ok = true;
        for(int j = i; j <= N; j += i) {
            if(bad[j]) {
                ok = false;
                break;
            }
        }
        
        if(ok) {
            std::cout << 1 << '\n' << i << '\n';
            return;
        }
    }

    std::cout << 2 << '\n' << N << ' ';
    for(int i = 2; i <= N; i++) {
        if(N % i != 0) {
            std::cout << i << '\n';
            return;
        }
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
