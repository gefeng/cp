#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = -1;
    while(K) {
        bool end = true;
        for(int i = 1; i < N; i++) {
            if(A[i] > A[i - 1]) {
                A[i - 1] += 1;
                K -= 1;
                ans = i - 1;
                end = false;
                break;
            }
        }

        if(end) {
            break;
        }
    }

    if(K) {
        ans = -1;
    } else {
        ans += 1;
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
