#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> inc(N - 1, 0);
    for(int i = N - 2; i >= 0; i--) {
        int g = gcd(A[i + 1], A[i]);
        if(i == N - 2) {
            inc[i] = g;
        } else {
            if(inc[i + 1] == -1 || inc[i + 1] < g) {
                inc[i] = -1;
            } else {
                inc[i] = g;
            }
        }
    }

    int pre_g = -1;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            if(inc[i + 1] != -1) {
                std::cout << "Yes" << '\n';
                return;
            }
        } else if(i == N - 1) {
            std::cout << "Yes" << '\n';
            return;
        } else {
            int g = gcd(A[i - 1], A[i + 1]);
            if(pre_g != -1) {
                if(pre_g <= g && (i + 1 > N - 2 || inc[i + 1] >= g)) {
                    std::cout << "Yes" << '\n'; 
                    return;
                }
            } else {
                if(i + 1 > N - 2 || inc[i + 1] >= g) {
                    std::cout << "Yes" << '\n';
                    return;
                }
            }
            g = gcd(A[i - 1], A[i]); 
            if(pre_g != 1 && g < pre_g) {
                std::cout << "No" << '\n';
                return;
            }
            pre_g = g;
        }
    }

    std::cout << "No" << '\n';
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
