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

    std::vector<int> freq(N + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }

    int missing = 0;
    for(int i = 0; i < K; i++) {
        if(!freq[i]) {
            missing += 1;
        }
    }

    std::cout << (missing >= freq[K] ? missing : freq[K]) << '\n';
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
