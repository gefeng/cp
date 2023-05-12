#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

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

    LL sum = 0LL;
    for(int i = 1; i <= N; i++) {
        if(freq[i] > 1) {
            sum += 1LL * freq[i] * (freq[i] - 1) / 2;
        }
    }

    for(int i = 0; i < N; i++) {
        LL res = sum;
        if(freq[A[i]] > 1) {
            res -= 1LL * freq[A[i]] * (freq[A[i]] - 1) / 2; 
            res += 1LL * (freq[A[i]] - 1) * (freq[A[i]] - 2) / 2;
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
