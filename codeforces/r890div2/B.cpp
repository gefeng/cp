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

    if(N == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    int64_t cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            cnt += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != 1) {
            cnt -= A[i] - 1;
        }
    }

    if(cnt <= 0) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
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
