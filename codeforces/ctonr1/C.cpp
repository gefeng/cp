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
    bool has_one = false;
    bool has_zero = false;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == 1) {
            has_one = true;
        }
        if(A[i] == 0) {
            has_zero = true;
        }
    }

    if(!has_one) {
        std::cout << "YES" << '\n';
        return;
    }

    if(has_zero) {
        std::cout << "NO" << '\n';
        return;
    } 

    std::sort(A.begin(), A.end());
    
    for(int i = 1; i < N; i++) {
        if(A[i] - A[i - 1] == 1) {
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
