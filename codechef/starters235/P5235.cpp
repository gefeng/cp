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
        freq[A[i]]++;
    }

    int present = 0;
    for(int k = 0; k <= N; k++) {
        int res = k - present + std::max(0, freq[k] - k + present);
        present += freq[k] ? 1 : 0;
        std::cout << res << " \n"[k == N];
    }
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
