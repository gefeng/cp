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

    std::vector<int> A(N - 2);
    for(int i = 0; i < N - 2; i++) {
        std::cin >> A[i];
    }

    int pre = -1;
    for(int i = 0; i < N - 2; i++) {
        if(A[i] == 1) {
            if(pre != -1 && i - pre == 2) {
                std::cout << "NO" << '\n';
                return;
            }
            pre = i;
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
