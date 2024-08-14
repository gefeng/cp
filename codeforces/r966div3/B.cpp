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
        A[i] -= 1;
    }

    std::vector<int> taken(N, 0);
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            taken[A[i]] = 1;
        } else {
            bool ok = false;
            if(A[i] - 1 >= 0 && taken[A[i] - 1]) {
                ok = true;
            }
            if(A[i] + 1 < N && taken[A[i] + 1]) {
                ok = true;
            }

            if(!ok) {
                std::cout << "No" << '\n';
                return;
            }

            taken[A[i]] = 1;
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
