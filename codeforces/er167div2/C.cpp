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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int a = 0;
    int b = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(A[i] == 1) {
                a += 1;
            } else if(B[i] == 1) {
                b += 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == B[i] && A[i] != 0) {
            if(A[i] == 1) {
                if(a < b) {
                    a += 1;
                } else {
                    b += 1;
                }
            } else {
                if(a <= b) {
                    b -= 1;
                } else {
                    a -= 1;
                }
            }
        }
    }

    std::cout << std::min(a, b) << '\n'; 
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
