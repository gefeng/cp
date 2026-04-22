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
    int p1 = -1;
    int p2 = -1;
    for(int i = 1; i < n; i++) {
        if(S[i] == S[i - 1]) {
            p1 = i;
            break;
        }
    }

    if(p1 == -1) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = n - 1; i > 0; i--) {
        if(S[i] == S[i - 1]) {
            p2 = i;
            break;
        } 
    }

    if(p1 == p2) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = p1 + 1; i < p2; i++) {
        if(S[i] == S[i - 1]) {
            std::cout << "NO" << '\n';
            return;
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
