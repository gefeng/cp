#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M, D;
    std::cin >> M >> D;

    std::array<int, 3> A = {};
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    int c = 0;
    for(int i = 2; i >= 0; i--) {
        if(i == 2) {
            A[i] += 1;
            if(A[i] > D) {
                A[i] = 1;
                c = 1;
            } else {
                c = 0;
            }
        } else if(i == 1) {
            A[i] += c;
            if(A[i] > M) {
                A[i] = 1; 
                c = 1;
            } else {
                c = 0;
            }
        } else {
            A[i] += c;
        }
    }

    for(int i = 0; i < 3; i++) {
        std::cout << A[i] << " \n"[i == 2];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
