#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(2e6);

std::vector<int> freq(MAX + 1, 0);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> all;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int x = A[i] ^ A[j];
            all.push_back(x);
            freq[x] += 1; 
        }
    }

    int64_t ans = 0;
    for(int x : all) {
        if(freq[x]) {
            int64_t f = freq[x];
            ans += f * (f - 1) * 4;
            freq[x] = 0;
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
