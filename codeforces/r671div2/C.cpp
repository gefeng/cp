#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == X) {
            cnt += 1;
        }
    }

    if(cnt == N) {
        std::cout << 0 << '\n';
        return;
    }

    if(cnt) {
        std::cout << 1 << '\n';
        return;
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += X - A[i];
    }

    std::cout << (sum == 0 ? 1 : 2) << '\n';
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
