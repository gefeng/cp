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
    int p_1 = 0;
    int p_2 = 0;
    int p_n = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
        if(A[i] == 1) {
            p_1 = i;
        }
        if(A[i] == 2) {
            p_2 = i;
        }
        if(A[i] == N) {
            p_n = i;
        }
    }
    
    if((p_n > p_1 && p_n < p_2) || (p_n > p_2 && p_n < p_1)) {
        std::cout << p_n + 1 << ' ' << p_n + 1 << '\n';
    } else {
        if(p_n < std::min(p_1, p_2)) {
            std::cout << std::min(p_1, p_2) + 1 << ' ' << p_n + 1 << '\n';           
        } else {
            std::cout << std::max(p_1, p_2) + 1 << ' ' << p_n + 1 << '\n';
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
