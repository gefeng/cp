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

    std::vector<int> suffix(N + 1, 0);
    std::array<int, 4> freq{};
    for(int l = N - 2, r = N - 2; l >= 0; l--) {
        freq[A[l]]++;
        while(l <= r && freq[3] > freq[1] + freq[2]) {
            freq[A[r]]--;
            r--;
        }
        if(l <= r) {
            suffix[N - l] = 1;
        }
    }

    freq.fill(0);
    for(int i = 0; i < N - 2; i++) {
        freq[A[i]]++;
        if(freq[1] >= freq[2] + freq[3] && suffix[N - 1 - i]) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
