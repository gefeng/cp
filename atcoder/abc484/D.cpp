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

    int64_t ans = 1;
    std::vector<int64_t> freq(N + 1, 0);
    std::vector<int64_t> groups(N + 1, 0);
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[j] == A[i]) {
            i++;
        }

        ans += j - freq[A[j]] + groups[A[j]];
        freq[A[j]] += i - j + 1;
        groups[A[j]]++;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
