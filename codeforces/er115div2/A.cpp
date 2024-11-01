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

    std::vector<std::string> A(2);
    for(int i = 0; i < 2; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[0][i] == '1' && A[1][i] == '1') {
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
