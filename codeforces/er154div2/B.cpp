#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    int n = S.size();

    if(S == T) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = 1; i < n - 1; i++) {
        if(S[i] == T[i]) {
            if(S[i] == '0') {
                bool ok = true;
                for(int j = i + 1; j < n - 1; j++) {
                    if(T[j] != S[j]) {
                        ok = false;
                        break;
                    } 

                    if(S[j] == '1') {
                        break;
                    }
                }

                if(ok) {
                    std::cout << "YES" << '\n';
                    return;
                }
            }
        }
    }

    for(int i = n - 2; i > 0; i--) {
        if(S[i] == T[i]) {
            if(S[i] == '1') {
                bool ok = true;
                for(int j = i - 1; j > 0; j--) {
                    if(S[j] != T[j]) {
                        ok = false;
                        break;
                    } 

                    if(S[j] == '0') {
                        break;
                    }
                }

                if(ok) {
                    std::cout << "YES" << '\n';
                    return;
                }
            }
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
