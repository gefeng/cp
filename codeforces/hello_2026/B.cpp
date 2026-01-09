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
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    int cnt = 0;
    for(int i = 0; i <= N; i++) {
        cnt += std::max(0, freq[i] - 1);
    }

    for(int i = N; i >= 0; i--) {
        if(freq[i] == 0) {
            continue;
        }
        if(cnt < N - K + 1) {
            cnt += 1;
            freq[i] = 0;
        }
    }

    int mex = 0;
    for(int i = 0; i <= N; i++) {
        if(freq[i]) {
            mex += 1;
        } else {
            break;
        }
    }

    std::cout << mex << '\n';
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
