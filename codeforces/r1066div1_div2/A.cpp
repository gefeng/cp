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

    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        freq[A[i]] += 1;
    }

    int ans = 0;
    for(int i = 0; i <= N; i++) {
        if(freq[i]) {
            if(freq[i] < i) {
                ans += freq[i];
            } else {
                ans += freq[i] - i;
            }
        }
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
