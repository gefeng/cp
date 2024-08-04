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

    std::vector<int> A(N << 1);
    int cnt_eve = 0;
    for(int i = 0; i < (N << 1); i++) {
        std::cin >> A[i];
        if(A[i] % 2 == 0) {
            cnt_eve += 1;
        }
    }

    std::cout << (cnt_eve == N ? "Yes" : "No") << '\n';
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
