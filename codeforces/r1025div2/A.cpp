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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i + 1 < N && A[i] == 0 && A[i + 1] == 0) {
            std::cout << "Yes" << '\n';
            return;
        }
        cnt += A[i] == 0 ? 1 : 0;
    }

    std::cout << (cnt == 0 ? "Yes" : "No") << '\n';
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
