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

    int ans = 0;
    int min_winner = (int)1e9;
    int min_v = (int)1e9;
    for(int i = 0; i < N; i++) {
        if(A[i] > min_v) {
            if(min_winner > A[i]) {
                ans += 1;
                min_winner = A[i];
            }
        }
        min_v = std::min(min_v, A[i]);
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
