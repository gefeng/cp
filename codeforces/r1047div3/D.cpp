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

    std::vector<int> ans(N);
    std::vector<int> freq(N + 1, 0);
    std::vector<int> val(N + 1, 0);
    
    int now = 1;
    for(int i = 0; i < N; i++) {
        if(freq[A[i]] == 0) {
            freq[A[i]] = A[i];
            val[A[i]] = now++;
            ans[i] = val[A[i]];
            freq[A[i]] -= 1;
        } else {
            ans[i] = val[A[i]];
            freq[A[i]] -= 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(freq[i]) {
            std::cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
