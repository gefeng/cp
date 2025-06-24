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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int a = 0;
    int b = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            if(A[i] == 1) {
                a += 1;
                b += 1;
            }
        } else if(A[i] == 0) {
            b += 1;
        } else {
            cnt += 1;
        }
    }

    if(a > b) {
        std::cout << 1 << '\n';
        return;
    }

    if(cnt == 0) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = (b - a + 1 + cnt - 1) / cnt;
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
