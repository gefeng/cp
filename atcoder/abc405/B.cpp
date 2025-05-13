#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> freq(M + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        bool good = true;
        for(int j = 1; j <= M; j++) {
            if(freq[j]) {
                continue;
            }
            good = false; 
        }

        if(!good) {
            break;
        }
        freq[A[i]] -= 1;
        ans += 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
