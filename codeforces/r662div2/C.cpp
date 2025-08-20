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
    std::vector<int> freq(N + 1, 0);
    int max_f = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
        max_f = std::max(max_f, freq[A[i]]);
    }

    if(max_f > (N + 1) / 2) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt_mf = 0;
    for(int i = 0; i <= N; i++) {
        if(max_f == freq[i]) {
            cnt_mf += 1;
        }
    }

    int left = N - max_f * cnt_mf;

    std::cout << cnt_mf - 1 + left / (max_f - 1) << '\n';
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
