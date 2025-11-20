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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt = 0;
    int max_c = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] <= X - 1) {
            cnt += 1;
        }
    }

    max_c = cnt;
    ans = X - 1;
    cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] >= X + 1) {
            cnt += 1;
        }
    }

    if(cnt > max_c) {
        ans = X + 1;
    }

    std::cout << ans << '\n';
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
