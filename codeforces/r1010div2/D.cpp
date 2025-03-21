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
    int l = -1;
    int r = -1;
    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i + 1]) {
            cnt += 1;
            l = l == -1 ? i : l;
            r = i + 1;
        }
    }

    if(cnt == 0) {
        std::cout << 0 << '\n';
        return;
    }

    if(A[r] - A[l] >= r - l) {
        std::cout << (cnt + 1) / 2 << '\n'; 
    } else {
        std::cout << cnt / 2 + 1 << '\n';
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
