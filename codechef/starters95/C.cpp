#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int h = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 63; j >= 0; j--) {
            if(A[i] & (1LL << j)) {
                h = std::max(h, j);
                break;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] & (1LL << h)) {
            cnt += 1;
        }
    }

    std::cout << (cnt + 1) / 2 << '\n';
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
