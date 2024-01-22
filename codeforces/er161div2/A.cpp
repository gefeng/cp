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

    std::string A, B, C;
    std::cin >> A >> B >> C;

    auto is_upper = [](char c) {
        return c >= 'A' && c <= 'Z';
    };

    bool ans = false;
    for(int i = 0; i < N; i++) {
        if(!is_upper(C[i])) {
            if(std::tolower(A[i]) != std::tolower(C[i]) && std::tolower(B[i]) != std::tolower(C[i])) {
                ans = true;
                break;
            }

            if(A[i] == B[i] && !is_upper(A[i]) && A[i] != C[i]) {
                ans = true; 
                break;
            }
        } else {
            if(std::tolower(A[i]) != std::tolower(C[i]) && std::tolower(B[i]) != std::tolower(C[i])) {
                ans = true;
                break;
            }

            if(A[i] == B[i] && !is_upper(A[i])) {
                ans = true;
                break;
            }
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
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
