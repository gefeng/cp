#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int cap = K;
    for(int i = 0; i < N; i++) {
        if(A[i] <= cap) {
            cap -= A[i]; 
            if(i == N - 1) {
                ans += 1;
            }
        } else {
            ans += 1;
            cap = K;
            i -= 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
