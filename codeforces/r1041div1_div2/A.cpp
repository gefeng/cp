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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            std::cout << "No" << '\n';
            return;
        }     
    }

    int t = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] != -1) {
            if(t == -1) {
                t = A[i];
            } else {
                if(t != A[i]) {
                    std::cout << "No" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "Yes" << '\n';
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
